#!/usr/bin/python

"""
mutiple process example

"""

import random
from multiprocessing import Process, Queue
import os

def put_num(que):
    num = random.randint(1, 100)
    que.put(num)
    print(f'put num {num} on pid {os.getpid()}')

def main():
    queue = Queue()

    childs = []
    for i in range(4):
        p = Process(target=put_num, args=(queue,))
        childs.append(p)
        p.start()

    for p in childs:
        p.join(10 * 1000)

    results = [queue.get() for p in childs]
    print(results)

if __name__ == '__main__':
    main()

