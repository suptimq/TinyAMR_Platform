import torch
import torch.optim as optim
import torch.nn.functional as F
import torchvision
import torchvision.datasets as datasets
import torchvision.models as models
import torchvision.transforms as transforms

# %%
'''
### Upload and extract dataset

Before you start, you should upload the ``dataset.zip`` file that you created in the ``data_collection.ipynb`` notebook on the robot.

You should then extract this dataset by calling the command below
'''
# unzip -q dataset.zip
'''
You should see a folder named ``dataset`` appear in the file browser.
### Create dataset instance
Now we use the ``ImageFolder`` dataset class available with the ``torchvision.datasets`` package.  We attach transforms from the ``torchvision.transforms`` package to prepare the data for training.  
'''
dataset = datasets.ImageFolder(
    'dataset',
    transforms.Compose([
        transforms.ColorJitter(0.1, 0.1, 0.1, 0.1),
        transforms.Resize((224, 224)),
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
    ]))

'''
### Split dataset into train and test sets
Next, we split the dataset into *training* and *test* sets.  The test set will be used to verify the accuracy of the model we train.
'''
train_dataset, test_dataset = torch.utils.data.random_split(
    dataset, [len(dataset) - 50, 50])

'''
### Create data loaders to load data in batches
We'll create two ``DataLoader`` instances, which provide utilities for shuffling data, producing *batches* of images, and loading the samples in parallel with multiple workers.
'''
train_loader = torch.utils.data.DataLoader(train_dataset,
                                           batch_size=16,
                                           shuffle=True,
                                           num_workers=4)

test_loader = torch.utils.data.DataLoader(test_dataset,
                                          batch_size=16,
                                          shuffle=True,
                                          num_workers=4)
'''
### Define the neural network
Now, we define the neural network we'll be training.  The *torchvision* package provides a collection of pre-trained models that we can use.
In a process called *transfer learning*, we can repurpose a pre-trained model (trained on millions of images) for a new task that has possibly much less data available.
Important features that were learned in the original training of the pre-trained model are re-usable for the new task.  We'll use the ``alexnet`` model.
'''
# model = models.alexnet(pretrained=True)
model = models.resnet18(pretrained=True)

'''
The ``alexnet`` model was originally trained for a dataset that had 1000 class labels, but our dataset only has two class labels!  We'll replace
the final layer with a new, untrained layer that has only two outputs.  
'''
# model.classifier[6] = torch.nn.Linear(model.classifier[6].in_features, 2)
model.fc = torch.nn.Linear(model.fc.in_features, 2)
'''
Finally, we transfer our model for execution on the GPU
'''

device = torch.device('cuda')
model = model.to(device)
'''
### Train the neural network
Using the code below we will train the neural network for 30 epochs, saving the best performing model after each epoch.
> An epoch is a full run through our data.
'''
NUM_EPOCHS = 30
BEST_MODEL_PATH = 'best_model.pth'
best_accuracy = 0.0

optimizer = optim.SGD(model.parameters(), lr=0.001, momentum=0.9)

for epoch in range(NUM_EPOCHS):

    for images, labels in iter(train_loader):
        images = images.to(device)
        labels = labels.to(device)
        optimizer.zero_grad()
        outputs = model(images)
        loss = F.cross_entropy(outputs, labels)
        loss.backward()
        optimizer.step()

    test_error_count = 0.0
    for images, labels in iter(test_loader):
        images = images.to(device)
        labels = labels.to(device)
        outputs = model(images)
        test_error_count += float(
            torch.sum(torch.abs(labels - outputs.argmax(1))))

    test_accuracy = 1.0 - float(test_error_count) / float(len(test_dataset))
    print('%d: %f' % (epoch, test_accuracy))
    if test_accuracy > best_accuracy:
        torch.save(model.state_dict(), BEST_MODEL_PATH)
        best_accuracy = test_accuracy
'''
Once that is finished, you should see a file ``best_model.pth`` in the Jupyter Lab file browser.  Select ``Right click`` -> ``Download`` to download the model to your workstation
'''
