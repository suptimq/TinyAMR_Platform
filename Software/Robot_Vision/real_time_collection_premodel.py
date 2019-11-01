import os
import cv2
import numpy as np
import torch
import torchvision
import torch.nn.functional as F
import time
from camera import Camera
from uuid import uuid1


# neural network (alextnet and resnet-18)
# model = torchvision.models.alexnet(pretrained=False)
# model.classifier[6] = torch.nn.Linear(model.classifier[6].in_features, 2)

model = models.resnet18(pretrained=False)
model.fc = torch.nn.Linear(model.fc.in_features, 2)

# load the trained weights from the best_model.pth file
model.load_state_dict(torch.load('best_model.pth'))
print('load model')

# transfer the code to the GPU device
device = torch.device('cuda')
model = model.to(device)
print('to GPU')


# image preprocess
mean = 255.0 * np.array([0.485, 0.456, 0.406])
stdev = 255.0 * np.array([0.229, 0.224, 0.225])

normalize = torchvision.transforms.Normalize(mean, stdev)


# 1. Convert from BGR to RGB
# 2. Convert from HWC layout to CHW layout
# 3. Normalize using same parameters as we did during training (our camera provides values in [0, 255] range and training loaded images in [0, 1] range so we need to scale by 255.0
# 4. Transfer the data from CPU memory to GPU memory
# 5. Add a batch dimension
def preprocess(camera_value):
    global device, normalize
    x = camera_value
    x = cv2.cvtColor(x, cv2.COLOR_BGR2RGB)
    x = x.transpose((2, 0, 1))
    x = torch.from_numpy(x).float()
    x = normalize(x)
    x = x.to(device)
    x = x[None, ...]
    return x


cap_time = 5                                  # save an image every 5 seconds
blocked_dir = 'dataset/blocked'
free_dir = 'dataset/free'

try:
    os.makedirs(free_dir)
    os.makedirs(blocked_dir)
except FileExistsError:
    print('Directories not created becasue they already exist')

# real time collection
def collect(change):
	global cap_time
	img = change['new']
	# copy image and input to neural network
    x = img.copy()
    x = preprocess(x)
    y = model(x)

    # we apply the `softmax` function to normalize the output vector so it sums to 1 (which makes it a probability distribution)
    y = F.softmax(y, dim=1)

    prob_blocked = float(y.flatten()[0])

	# free
    if prob_blocked < 0.5:
		image_path = os.path.join(free_dir, str(uuid1()) + '.jpg')
    else:
		image_path = os.path.join(blocked_dir, str(uuid1()) + '.jpg')

	# save the original image instead of the preprocessed one
	cv2.imwrite(image_path, img)

    time.sleep(cap_time)


# set up camera
camera = Camera(show=True)
print('camera sets up')

print('attach camera with model')
camera.observe(update, names='value')
