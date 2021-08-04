#!/usr/bin/python
"""
download images using multiple process

"""

"""
use multiprocess.Pool will have following error:

multiprocessing.pool.MaybeEncodingError: 
Error sending result: 
'<multiprocessing.pool.ExceptionWithTraceback object at 0x7f14fa3f0278>'. Reason: 'TypeError("cannot serialize '_io.BufferedReader' object",)'

use ThreadPool to solve this issue

"""

import urllib.request
import hashlib
import os
from multiprocessing.dummy import Pool

image_save_path = '/home/jason/Downloads'

def download_image(url):
    """
    get image url from the queue and 
    downlowd it to given path
    """

    print(f'start downloading {url}')
    sha256 = hashlib.sha256()
    sha256.update(url.encode('utf-8'))

    saved_image = image_save_path + os.sep + sha256.hexdigest() + '.jpeg'

    urllib.request.urlretrieve(url, saved_image)
    print(f'download image {url} done')

    return saved_image

def main():
    img_url = ['https://images.unsplash.com/photo-1627959449111-d29a72e1a41c?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=1050&q=80',
        'https://images.unsplash.com/photo-1627933907906-6075f7c88da5?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=334&q=80',
        'https://images.unsplash.com/photo-1627959449028-22c2fc9e138b?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=334&q=80',
        'https://images.unsplash.com/photo-1627933895547-5e2d2558d846?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=334&q=80',
        'https://images.unsplash.com/photo-1627959449042-1812aac29602?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=334&q=80']
    
    #pool = mp.Pool(mp.cpu_count())
    #pool.map(download_image, img_url)
    pool = Pool(3)
    result = pool.map(download_image, img_url)

    for res in result:
        print(res)

if __name__ == '__main__':
    main()
    

