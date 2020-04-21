# 爬取百度首页

import requests


def main():
    url = "https://www.baidu.com"
    print(get_HTML_text(url))


def get_HTML_text(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常!!!"


if __name__ == "__main__":
    main()