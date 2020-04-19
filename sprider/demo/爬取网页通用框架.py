import requests


def main():
    url = "https://www.baidu.com"
    print(get_HTML_text(url))


def get_HTML_text(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常!!!"


if __name__ == "__main__":
    main()
