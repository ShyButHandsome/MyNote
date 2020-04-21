# 实现Bing搜索

import requests


def main():
    url = "https://www.bing.com/search"
    word = "ShyButHandsome"
    print(get_HTML_text(url, word))


def get_HTML_text(url, keyWord):
    keyWordDic = {'q': keyWord}
    try:
        r = requests.get(url, params=keyWordDic)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常!!!"


if __name__ == "__main__":
    main()
