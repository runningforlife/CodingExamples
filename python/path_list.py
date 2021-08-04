#!/usr/bin/python

import os.path
import sys
import os

def find_file():
    cwd = os.getcwd()
    for dir_path, dir_name, files in os.walk(cwd):
        for f in files:
            print(os.path.join(dir_path, f))

def main():
    find_file()

if __name__ == '__main__':
    main()

