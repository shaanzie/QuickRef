# Multithreaded priority queue

from queue import PriorityQueue
import threading
import time
import random

flag = 0

class MakeThread(threading.Thread):

    def __init__(self, ID, name, list_queue):
        threading.Thread.__init__(self)
        self.ID = ID
        self.name = name
        self.list_queue = list_queue

    def run(self):
        compute(self.name, self.list_queue)

def compute(threadName, q):
    while not flag:
        lock_queue.acquire()
        if not some_queue.empty():
            pop = q.get()
            lock_queue.release()
            print("Taken " + threadName + " " + str(pop))
        else:
            lock_queue.release()
    

threads = ["Thread1", "Thread2", "Thread3", "Thread4", "Thread5"]
lock_queue = threading.Lock()
some_queue = PriorityQueue(100)
count = 0
computingThreads = list()

for t in threads:
    count += 1
    thread = MakeThread("Thread"+str(count), t, some_queue)
    thread.start()
    computingThreads.append(thread)

lock_queue.acquire()
for i in range(1, 100):
    some_queue.put(random.randint(1, 100))
lock_queue.release()

while not some_queue.empty():
    pass

flag = 1

for t in threads:
    t.join()