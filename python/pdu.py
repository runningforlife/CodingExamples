#/usr/bin/python

"""a disk usage program using python"""

import os
import queue
import multiprocessing
import argparse
from threading import Thread


class PathInfo:

    def __init__(self, file_path, file_sz):
        self.fp = file_path
        self.fs = file_sz

    def getFilePath(self):
        return self.fp

    def getFileSize(self):
        return self.fs

class DiskUsageCheck(Thread):

    def __init__(self, que, p):
        Thread.__init__(self)
        self.que = que
        self.path = p

    def run(self):
        file_size = 0

        if os.path.isfile(self.path):
            file_size += os.path.getsize(self.path)
        elif os.path.isdir(self.path):
            
            for (d, d_name, file_names) in os.walk(self.path):
                for f in file_names:, 
                    file = os.path.join(d, f)
                    #print('file: ', f)
                    file_size += os.path.getsize(file)

        print(f'total size of {self.path} is {file_size/1024.0/1024.0} MB')
        
        self.que.put(PathInfo(self.path, file_size))

        self.que.task_done()

def main(p):
    q = queue.Queue()
    if os.path.exists(p):
        duThread = DiskUsageCheck(q, p)
        duThread.start()
    
    q.join()

    pathInfo = q.get(3000)
    print(f'{pathInfo.fp} file size is {pathInfo.fs}')

def parseArgs():
    argParse = argparse.ArgumentParser()
    argParse.add_argument('-p', required=True, metavar='file path to check', help='check file size of given path')

    return argParse.parse_args()

if __name__ == "__main__":
    args = parseArgs()

    main(args.p)

