import os
import cv2
import time
from uuid import uuid1
from camera import Camera


cnt = 0
cap_time = 5                                  # save an image every 5 seconds
directory = 'dataset'

# real time data collection
def collect(change):
	global cnt, directory
	x = change['new']
	image_path = os.path.join(directory, str(uuid1()) + '.jpg')
	
	print('---------------------------------')
	print('image shape: {}'.format(x.shape))
	cnt += 1
	
	cv2.imwrite(image_path, x)
	print('save {}th image'.format(cnt))

	time.sleep(cap_time)

	
# set up camera
camera = Camera(show=False)
print('camera sets up')


print('attach camera with model')
camera.observe(collect, names='value')
