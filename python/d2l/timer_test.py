#!/usr/bin/python
from timer import Timer
import math
from mxnet import np
from d2l import mxnet as d2l

def scalar_cal(a, b):
    c = np.zeros(n)
    timer = Timer()

    for i in range(n):
        c[i] = a[i] + b[i]

    print(f'scalar_cal takes {timer.stop():.5f} sec')

def vector_cal(a, b):
    timer = Timer()

    c = a + b
    print(f' vector_cal takes {timer.stop():.5f} sec')


if __name__ == '__main__':
    n = 10000
    a = np.ones(n)
    b = np.ones(n)

    scalar_cal(a, b)
    vector_cal(a,b)
