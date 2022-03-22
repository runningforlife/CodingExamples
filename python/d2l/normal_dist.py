#%matplotlib inline
import math
import time
from mxnet import np
from d2l import mxnet as d2l

def normal(x, mu, sigma):
    p = 1/ math.sqrt(2 * math.pi * sigma**2)
    return p * np.exp(-0.5 / sigma**2 * (x - mu)**2)


def plot_normal_dist():
    x = np.arange(-7, 7, 0.01)

    params = [(0, 1), (0, 2), (3, 1)]
    #params = [(0, 1)]
    d2l.plot(x, [normal(x, mu, sigma) for mu, sigma in params], xlabel='x', ylabel='p(x)', figsize=(4.5, 2.5), legend=[f'mean{mu}, std{sigma}' for mu, sigma in params])


if __name__ == '__main__':
    plot_normal_dist()
