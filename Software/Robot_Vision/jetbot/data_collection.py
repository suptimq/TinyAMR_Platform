import traitlets
import ipywidgets.widgets as widgets
from IPython.display import display
from jetbot import Camera, bgr8_to_jpeg

# initialize and display our camera like we did in the teleoperation notebook
camera = Camera.instance(width=224, height=224)

image = widgets.Image(
    format='jpeg', width=224, height=224
)  # this width and height doesn't necessarily have to match the camera

camera_link = traitlets.dlink((camera, 'value'), (image, 'value'),
                              transform=bgr8_to_jpeg)

display(image)

# create a few directories where we'll store all our data
import os

blocked_dir = 'dataset/blocked'
free_dir = 'dataset/free'

try:
    os.makedirs(free_dir)
    os.makedirs(blocked_dir)
except FileExistsError:
    print('Directories not created becasue they already exist')

# create and display some buttons
button_layout = widgets.Layout(width='128px', height='64px')
free_button = widgets.Button(description='add free',
                             button_style='success',
                             layout=button_layout)
blocked_button = widgets.Button(description='add blocked',
                                button_style='danger',
                                layout=button_layout)
free_count = widgets.IntText(layout=button_layout,
                             value=len(os.listdir(free_dir)))
blocked_count = widgets.IntText(layout=button_layout,
                                value=len(os.listdir(blocked_dir)))

display(widgets.HBox([free_count, free_button]))
display(widgets.HBox([blocked_count, blocked_button]))

# make sure we don't repeat any file names
from uuid import uuid1


def save_snapshot(directory):
    image_path = os.path.join(directory, str(uuid1()) + '.jpg')
    with open(image_path, 'wb') as f:
        f.write(image.value)


def save_free():
    global free_dir, free_count
    save_snapshot(free_dir)
    free_count.value = len(os.listdir(free_dir))


def save_blocked():
    global blocked_dir, blocked_count
    save_snapshot(blocked_dir)
    blocked_count.value = len(os.listdir(blocked_dir))


# attach the callbacks, we use a 'lambda' function to ignore the
# parameter that the on_click event would provide to our function
# because we don't need it.
free_button.on_click(lambda x: save_free())
blocked_button.on_click(lambda x: save_blocked())

# display(image)
# display(widgets.HBox([free_count, free_button]))
# display(widgets.HBox([blocked_count, blocked_button]))

# save dataset
# zip -r -q dataset.zip dataset
