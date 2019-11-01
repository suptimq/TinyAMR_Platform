import logging
import threading
import keyboard
import time
import sys


def set_logging(log_file, log_level=logging.DEBUG):
    """
    Logging to log file.
    """
    log_format = '[%(asctime)s] - [%(name)s] - [%(levelname)s] - %(message)s'
    logging.basicConfig(level=log_level, format=log_format, filename=log_file)
    return logging.getLogger()

done = False
logger = set_logging(log_file='log.txt')
logger.info('Main: create thread')


def key_press(key):
    global done
    print(key.name)
    if key.name == 'q':
        done = True


if __name__ == '__main__':

    keyboard.on_press(key_press)

    while True and not done:
        time.sleep(1)
        print('here')

    # sys.stdout.flush()
    # read_thread = threading.Thread(target=read_keyborad)
    # read_thread.start()