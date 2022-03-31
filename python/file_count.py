
import os
import glob
import argparse

def count_file(path, file_type):
    """return the number of files under given path"""
    #files = path + '/*' + file_type
    files = str(path + '/*' + file_type)
    fs = glob.glob(files, recursive=True)
    total = len(fs)
    print(f'found {total} files under {path}')
    return total

def parse_args():
    parse = argparse.ArgumentParser()
    parse.add_argument('-p', type=str, required=True, help='file searching path')
    parse.add_argument('-t', type=str, required=True, help='file type to count')

    return parse.parse_args()

if __name__ == "__main__":
    args = parse_args()
    file_path = args.p
    file_type = args.t
    print(f'file path is {file_path}, file type is {file_type}')

    fts = file_type.split(',')
    total = 0
    for ft in fts:
        res = count_file(file_path, ft)
        total += res

    print(f'found {total} files under {file_path}')
