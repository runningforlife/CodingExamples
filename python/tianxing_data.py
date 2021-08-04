#!/usr/bin/python
# -*- coding:utf-8 -*-

import sys
import urllib.request
#import urllib3
import json
import random

API_KEY = '44c1e2c8247379af10883f3637ec82c6'
# news url
NEWS_URL = 'http://api.tianapi.com'
# funny data
FUNNY_URL = 'http://api.tianapi.com/txapi'
# news category
news_category = ['auto', 'ai', 'internet']

def build_news_url(news_category, api_key, news_num):
    result = NEWS_URL + '/' + news_category + '/index?'
    result += 'key=' + api_key + '&num=' + str(news_num)
    return result

def get_some_news():
    """get some random news"""
    ridx = random.randint(0, 3)
    ridx = ridx % len(news_category)
    
    news_cat = news_category[ridx]
    print("Getting " + news_cat + " news, waiting for while")

    news_url = build_news_url(news_cat, API_KEY, 10)

    print("news URL: " + news_url)
    resp = urllib.request.urlopen(news_url)
    content = resp.read().decode('utf-8')

    return content

def format_news(content):
    """format news if user input enter"""
    key_ctime = 'ctime'
    key_desc = 'description'
    key_list = 'newslist'

    news_content = json.loads(content, encoding='utf-8')
    print('news content type: ' + str(type(news_content)))
    news_list = news_content[key_list]
    print('news type: ' + str(type(news_list)))
    curr = 0
    while True:
        try:
            if curr < len(news_list):
                news = news_list[curr]
                print(news[key_ctime])
                print(news[key_desc])
                curr += 1
            else:
                break
            #user_input = input()
        except EOFError as eof:
            break

def main():
    print('Getting some news to relax')
    content = get_some_news()
    format_news(content)

if __name__ == '__main__':
    main()
