"""a timer class to caculate execution time"""
import time
from mxnet import np

class Timer:

    def __init__(self):
        self.times = []
        self.start()

    def start(self):
        self.tick = time.time()

    def stop(self):
        self.times.append(time.time() - self.tick)
        return self.times[-1]

    def avg(self):
        return sum(self.times)/len(self.times)

    def sum(self):
        return np.array(self.times).cumsum().tolist()