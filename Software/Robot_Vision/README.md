# Mobile Robot Vision

## Folder

- `jetbot` folder contains the source code provided by [jetbot program](https://github.com/NVIDIA-AI-IOT/jetbot/tree/master/jetbot)
- `camera_test` folder contains the code for camera testing
- `config` configuration files

## Script

scripts that are able to run in local environment instead of Jupyter Notebook

- `camera.py` modify source code to support displaying camera image
- `real_time.py` real time capture images and classify them as blocked or free
- `real_time_collection.py` and `real_time_collection_premodel.py` capture images every certain time when robot is moving

>Difference between two data collection files is that pre-trained models are used for pre-classification in the second script

