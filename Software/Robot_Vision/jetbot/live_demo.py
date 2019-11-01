import torch
import torchvision

model = torchvision.models.alexnet(pretrained=False)
model.classifier[6] = torch.nn.Linear(model.classifier[6].in_features, 2)

# load the trained weights from the best_model.pth file
model.load_state_dict(torch.load('best_model.pth'))
print('load model')

# transfer the code to the GPU device
device = torch.device('cuda')
model = model.to(device)
print('to GPU')

import cv2
import numpy as np

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


import traitlets
from IPython.display import display
import ipywidgets.widgets as widgets
from jetbot import Camera, bgr8_to_jpeg

camera = Camera.instance(width=224, height=224)
image = widgets.Image(format='jpeg', width=224, height=224)
blocked_slider = widgets.FloatSlider(description='blocked',
                                     min=0.0,
                                     max=1.0,
                                     orientation='vertical')

camera_link = traitlets.dlink((camera, 'value'), (image, 'value'),
                              transform=bgr8_to_jpeg)

print('camera sets up')

# display(widgets.HBox([image, blocked_slider]))

#  create our robot instance which we'll need to drive the motors
# from jetbot import Robot

# robot = Robot()

# Pre-process the camera image
# Execute the neural network
# While the neural network output indicates we're blocked, we'll turn left, otherwise we go forward

import torch.nn.functional as F
import time


def update(change):
    # global blocked_slider, robot
    global blocked_slider
    x = change['new']
    x = preprocess(x)
    y = model(x)

    # we apply the `softmax` function to normalize the output vector so it sums to 1 (which makes it a probability distribution)
    y = F.softmax(y, dim=1)

    prob_blocked = float(y.flatten()[0])

    blocked_slider.value = prob_blocked

    if prob_blocked < 0.5:
        # robot.forward(0.4)
        print('forward')
    else:
        # robot.left(0.4)
        print('turn left')

    time.sleep(0.001)


update({'new': camera.value})  # we call the function once to intialize
print('initialize camera')

# this attaches the 'update' function to the 'value' traitlet of our camera
camera.observe(update, names='value')

# If you want to stop this behavior, you can unattach this callback by executing the code below.
# camera.unobserve(update, names='value')
# robot.stop()

# camera_link.unlink()  # don't stream to browser (will still run camera)
# camera_link.link()  # stream to browser (wont run camera)
