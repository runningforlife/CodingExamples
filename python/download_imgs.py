#!/usr/bin/python

import urllib.request
import sys
import os

class ImageLoader:

    target_w = 1920
    target_h = 1080

    url_prefix = "https://images.unsplash.com/"
    saved_loc = "/home/jason/Pictures/Wallpapers/"

    """images file list to download"""
    images_file = ""

    def __init__(self, files):
        self.images_file = files

    def get_images_url_from_file(self):
        """get images url"""
        urls = []
        with open(self.images_file, "r") as f:
            lines = f.readlines()
            for line in lines:
                if line.startswith(self.url_prefix):
                    print("got image url " + line)
                    urls.append(line)
        return urls

    def get_current_imgs(self):
        result = []
        for r, d, f in os.walk(self.saved_loc):
            for fi in f:
                if (fi.endswith(".jpeg") or fi.endswith(".jpg")):
                    result.append(fi)
        return result

    def download_images(self):
        image_urls = self.get_images_url_from_file()
        """download all images from given urls"""
        for url in image_urls:
            self.download_img(url)

    def download_img(self, url):
        idx = url.find("w=")
        if idx != -1:
            target_url = url[:(idx - 1)] + "w=" + str(self.target_w) + "&h=" + str(self.target_h)
            print("target url:" + target_url)

            idx_s = url.find("photo")
            idx_e = url.find("?ix")
            file_name = url[idx_s : idx_e] + ".jpeg"
            print("saved file name: " + file_name)

            current_imgs = self.get_current_imgs()
            if not (file_name in current_imgs):
                urllib.request.urlretrieve(target_url, self.saved_loc + file_name)
            else:
                print(file_name + "is already downloaded")

def main(files):
    imgLoader = ImageLoader(files)

    imgLoader.download_images()

    print("download image done")


if __name__ == "__main__":
    print("download image from file " + sys.argv[1])
    main(sys.argv[1])
