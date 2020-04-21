# 爬取知乎

import requests


def main():
    url = "https://zhuanlan.zhihu.com/p/35625779"  # 知乎Ban掉了requests Spider
    print(get_HTML_text(url))


def get_HTML_text(url):
    try:
        # headers选项的使用，不改就503了
        head = {'user-agent': 'Mozilla/5.0'}
        r = requests.get(url, headers=head)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常!!!"


if __name__ == "__main__":
    # @Dwzb的文章
    main()
