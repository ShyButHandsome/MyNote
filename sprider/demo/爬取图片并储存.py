# 爬取图片并保存

import requests
import os

root = "C://Users//ShyBu//Pictures//wall//"

def main():
    url = "https://w.wallhaven.cc/full/ox/wallhaven-ox83gp.jpg"  # wallhaven的壁纸
    download_wall(url)

def download_wall(url):
    path = root + url.split("/")[-1]
    try:
        if not os.path.exists(root):
            os.mkdir(root)
        if not os.path.exists(path):
            r = requests.get(url)
            r.raise_for_status()
            with open(path, 'wb') as f:
                f.write(r.content)  # content的使用
                f.close()
                print("图片下载完成！")
        else:
            print("文件已存在！")
    except:
        print("产生异常！！！")


if __name__ == "__main__":
    main()




