import sys
import threading
import time
import queue

def add_input(input_queue):
    while True:
        input_queue.put(sys.stdin.read(1))

def foobar():
    input_queue = queue.Queue()

    input_thread = threading.Thread(target=add_input, args=(input_queue,))
    input_thread.daemon = True
    input_thread.start()

    last_update = time.time()
    while True:

        # if time.time()-last_update>0.5:
        #     sys.stdout.write(".")
        #     last_update = time.time()

        if not input_queue.empty():
            print("input: ", input_queue.get())

        time.sleep(1)
        print('here')

foobar()