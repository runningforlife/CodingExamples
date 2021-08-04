import scrapy
import urllib.request

class WallPaperSpider(scrapy.Spider):
    name = "wallpaper"

    wp_width = 1920
    wp_height = 1080

    saved_file_count = 0
    saved_file_loc = "/home/jason/Pictures/"

    def start_requests(self):
        urls = ['https://unsplash.com/s/photos/girls-fashion',
                'https://unsplash.com/s/photos/sexy-girl']

        for url in urls:
            yield scrapy.Request(url=url, callback=self.parse)

    def download_save_image(self, url):
        file_name = self.saved_file_loc + self.saved_file_count + ".jpeg"

        urllib.request.urlretrive(url, file_name)
        self.saved_file_count += 1
        print("download done")

    def parse(self, response):
        page_url = response.url
        print("page url: " + page_url)
        if "https://images.unsplash.com/photo" in page_url:
            widx = page_url.find('&w=')
            if widx != -1:
                target_url = page_url[:widx] + '&w=' + str(wp_width) + '&h=' + str(wp_height)
                print("target url: " + target_url)

                if (self.saved_file_count < 100):
                    self.download_save_image(target_url)

def main():
    wallpaper_spider = WallPaperSpider()
    wallpaper_spider.start_requests()

if __name__ == "__main__":
    main()
