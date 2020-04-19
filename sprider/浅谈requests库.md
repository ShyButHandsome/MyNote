# 浅谈requests库

*安装*

```shell
pip install requests  # 是requests而不是request（有s的）
```

## requests的简单使用

```python
# requests的简单使用,看看效果就行,后面会更仔细细讲
import requests


r = requests.get("https://www.baidu.com") # 构造一个Request对象, 返回一个Response对象

print(r.status_code)  # 查看状态码，检查是否成功，200则为成功

print(r.encoding)  # 查看当前编码,默认为header的charset字段

print(r.apparent_encoding)  # 查看requests根据上下文判断的编码(备选编码)

r.encoding = 'utf-8' #此处我们是已知网页编码才这么写

# 一般来说，我们都是采取r.encoding = r.apparent_encoding 的方式让它自己转换编码

print(r.text)  # 查看获取到的网页内容

```

**简单拓展：（后续会更加详细的讲）**

|         方法         |                  说明                  |  `HTML`  |
| :------------------: | :------------------------------------: | :------: |
| `requests.request()` | 构造一个请求，支撑以下各方法的基础方法 |  $ALL$   |
|   `requests.get()`   |        获取`HTML`网页的主要方法        |  `GET`   |
|  `requests.head()`   |       获取`HTML`网页头信息的方法       |  `HEAD`  |
|  `requests.post()`   |    向`HTML`网页提交`POST`请求的方法    |  `POST`  |
|   `requests.put()`   |    向`HTML`网页提交`PUT`请求的方法     |  `PUT`   |
|  `requests.patch()`  |      向`HTML`网页提交局部修改请求      | `PATCH`  |
| `requsets.delete()`  |        向`HTML`页面提交删除请求        | `DELETE` |

## 从`requests.get()方法`看`requests库`

```python
r = requests.get(url)
```

`requests.get()`方法会
- **构造一个向服务器请求资源的`Requset对象`**
- **返回一个包含服务器资源的`Response对象`**

这里的`Response对象`就是`r`

```python
type(r)
# 在python console中返回的结果是 <class 'requests.models.Response'>
# 即, r是一个Response对象
```

`r`储存着所有从服务器返回的资源,同时也包含了我们向服务器请求的`Request`的信息

**`requests.get()`的完整使用:**

```python
requests.get(url, params = None, **kwargs)
```

- `url`: 拟获取(目标网站)的$url$链接
- `params`: `url`中的额外参数,字典或字节流格式(*可选*)
- `**kwargs` $12$个控制访问的参数(*可选*)

**探秘`get()`方法:**

*以下是`requsets/api.py`中的部分内容*

```python
def get(url, params=None, **kwargs):
    """Sends a GET request.

    :param url: URL for the new :class:`Request` object.
    :param params: (optional) Dictionary, list of tuples or bytes to send
        in the query string for the :class:`Request`.
    :param \*\*kwargs: Optional arguments that ``request`` takes.
    :return: :class:`Response <Response>` object
    :rtype: requests.Response
    """

    kwargs.setdefault('allow_redirects', True)
    return request('get', url, params=params, **kwargs)
```

我们可以发现:*(在上面的最后一行`return语句`)*

**`get()方法`是由`requsets()方法`封装得来的**

`requests库`一共提供了$7$个常用方法(*详见上文:`requests库`的简单使用*)

**实际上:**

**除了`request()方法`外**

**其他$6$个方法都是通过调用`request()方法`来实现的**

前面提到的:

> `requests.get()`方法会
>  - **构造一个向服务器请求资源的`Requset对象`**
>  - **返回一个包含服务器资源的`Response对象`**

`requests.get()方法`构造出的`Response对象`实质上是`requests()方法`构造出来的

**你甚至可以说`requests库`只有一个方法:`requests.request()`**

`requests.request()`构造出了两个重要的对象

`Request对象`(负责发请求),和

`Resopnse对象`(储存返回信息)

而这个`Response对象`包含了爬虫返回的全部内容,当属重中之重

**`Response对象`的几个常见且重要属性:**

|         属性          |                              说明                              |
| :-------------------: | :------------------------------------------------------------: |
|    `r.status_code`    | `HTTP`请求的返回状态,$200$表示连接成功,$404$(*等*)表示连接失败 |
|       `r.text`        |       `HTTP`响应内容的字符串形式,即,`url`对应的页面内容        |
|     `r.encoding`      |           从`HTTP header`中猜测的相应内容的编码方式            |
| `r.apparent_encoding` |         从内容中分析出相应内容编码方式(*备选编码方式*)         |
|      `r.content`      |                   `HTTP`响应内容的二进制形式                   |

**关于编码:**

`r.encoding`会从`header`的`charset`字段读取编码信息,

如果不存在`charset`字段,则默认编码为`ISO-8859-1`

**关于`Response对象`举几个小例子:**

- `r.status_code`: 和我们常见的"404,网站不见了"是一个道理
- `r.text`: 字符串形式储存着网页源码,编码方式是可以变的
- `r.content`: 假设你现在`get()`到了一个图片,那么这个图片,就是用二进制的形式存储的,那么就可以通过`r.content`来还原这张图片

**爬取网页信息的基本流程:**

```flow
get=>start: requests.get()
statu=>condition: r.status_code == 200
op1=>operation: 将r.text转换为可读编码
e1=>end: 进一步操作
op2=>operation: 产生异常
e2=>end: 进行调试
get->statu(yes)->op1->e1
get->statu(no)->op2->e2
```

```python
# 在python console的实践(实践出真知)
>>> import requests
>>> 
>>> r = requests.get("https://www.baidu.com")
>>> 
>>> type(r)
<class 'requests.models.Response'>
>>> 
>>> r.status_code  # 查看当前状态码,非200则产生了异常
200 
>>> # 状态码为200没有问题,可以进行下一步操作
... 
>>> r.encoding
'ISO-8859-1'
>>> # 默认就是'ISO-8859-1',但这种编码方式并不支持中文,我们可以直接打印试试
...    
>>> r.text  # python console中是展开的,复制到这就成了一行,可以拖动代码框底部滑块左右移动来观察
'<!DOCTYPE html>\r\n<!--STATUS OK--><html> <head><meta http-equiv=content-type content=text/html;charset=utf-8><meta http-equiv=X-UA-Compatible content=IE=Edge><meta content=always name=referrer><link rel=stylesheet type=text/css href=https://ss1.bdstatic.com/5eN1bjq8AAUYm2zgoY3K/r/www/cache/bdorz/baidu.min.css><title>ç\x99¾åº¦ä¸\x80ä¸\x8bï¼\x8cä½\xa0å°±ç\x9f¥é\x81\x93</title></head> <body link=#0000cc> <div id=wrapper> <div id=head> <div class=head_wrapper> <div class=s_form> <div class=s_form_wrapper> <div id=lg> <img hidefocus=true src=//www.baidu.com/img/bd_logo1.png width=270 height=129> </div> <form id=form name=f action=//www.baidu.com/s class=fm> <input type=hidden name=bdorz_come value=1> <input type=hidden name=ie value=utf-8> <input type=hidden name=f value=8> <input type=hidden name=rsv_bp value=1> <input type=hidden name=rsv_idx value=1> <input type=hidden name=tn value=baidu><span class="bg s_ipt_wr"><input id=kw name=wd class=s_ipt value maxlength=255 autocomplete=off autofocus=autofocus></span><span class="bg s_btn_wr"><input type=submit id=su value=ç\x99¾åº¦ä¸\x80ä¸\x8b class="bg s_btn" autofocus></span> </form> </div> </div> <div id=u1> <a href=http://news.baidu.com name=tj_trnews class=mnav>æ\x96°é\x97»</a> <a href=https://www.hao123.com name=tj_trhao123 class=mnav>hao123</a> <a href=http://map.baidu.com name=tj_trmap class=mnav>å\x9c°å\x9b¾</a> <a href=http://v.baidu.com name=tj_trvideo class=mnav>è§\x86é¢\x91</a> <a href=http://tieba.baidu.com name=tj_trtieba class=mnav>è´´å\x90§</a> <noscript> <a href=http://www.baidu.com/bdorz/login.gif?login&amp;tpl=mn&amp;u=http%3A%2F%2Fwww.baidu.com%2f%3fbdorz_come%3d1 name=tj_login class=lb>ç\x99»å½\x95</a> </noscript> <script>document.write(\'<a href="http://www.baidu.com/bdorz/login.gif?login&tpl=mn&u=\'+ encodeURIComponent(window.location.href+ (window.location.search === "" ? "?" : "&")+ "bdorz_come=1")+ \'" name="tj_login" class="lb">ç\x99»å½\x95</a>\');\r\n                </script> <a href=//www.baidu.com/more/ name=tj_briicon class=bri style="display: block;">æ\x9b´å¤\x9aäº§å\x93\x81</a> </div> </div> </div> <div id=ftCon> <div id=ftConw> <p id=lh> <a href=http://home.baidu.com>å\x85³äº\x8eç\x99¾åº¦</a> <a href=http://ir.baidu.com>About Baidu</a> </p> <p id=cp>&copy;2017&nbsp;Baidu&nbsp;<a href=http://www.baidu.com/duty/>ä½¿ç\x94¨ç\x99¾åº¦å\x89\x8då¿\x85è¯»</a>&nbsp; <a href=http://jianyi.baidu.com/ class=cp-feedback>æ\x84\x8fè§\x81å\x8f\x8dé¦\x88</a>&nbsp;äº¬ICPè¯\x81030173å\x8f·&nbsp; <img src=//www.baidu.com/img/gs.gif> </p> </div> </div> </div> </body> </html>\r\n'
>>> 
>>> # 可以发现出现了乱码(不出现才怪)
... # 接下来我们需要将r.text转换为可读编码,就是r.encoding和r.apparent_encoding的使用
... 
>>> r.apparent_encoding  # 查看备选编码方式
'utf-8'
>>> r.encoding = 'utf-8'  # 或者直接r.encoding = r.apparent_encoding
>>> 
>>> r.encoding
'utf-8'
>>> r.encoding  # 检查是否成功改变编码方式
'utf-8'
>>> # 成功更换,接下来看看效果吧
... 
>>> r.text  # python console中是展开的,复制到这就成了一行,可以拖动代码框底部滑块左右移动来观察
'<!DOCTYPE html>\r\n<!--STATUS OK--><html> <head><meta http-equiv=content-type content=text/html;charset=utf-8><meta http-equiv=X-UA-Compatible content=IE=Edge><meta content=always name=referrer><link rel=stylesheet type=text/css href=https://ss1.bdstatic.com/5eN1bjq8AAUYm2zgoY3K/r/www/cache/bdorz/baidu.min.css><title>百度一下，你就知道</title></head> <body link=#0000cc> <div id=wrapper> <div id=head> <div class=head_wrapper> <div class=s_form> <div class=s_form_wrapper> <div id=lg> <img hidefocus=true src=//www.baidu.com/img/bd_logo1.png width=270 height=129> </div> <form id=form name=f action=//www.baidu.com/s class=fm> <input type=hidden name=bdorz_come value=1> <input type=hidden name=ie value=utf-8> <input type=hidden name=f value=8> <input type=hidden name=rsv_bp value=1> <input type=hidden name=rsv_idx value=1> <input type=hidden name=tn value=baidu><span class="bg s_ipt_wr"><input id=kw name=wd class=s_ipt value maxlength=255 autocomplete=off autofocus=autofocus></span><span class="bg s_btn_wr"><input type=submit id=su value=百度一下 class="bg s_btn" autofocus></span> </form> </div> </div> <div id=u1> <a href=http://news.baidu.com name=tj_trnews class=mnav>新闻</a> <a href=https://www.hao123.com name=tj_trhao123 class=mnav>hao123</a> <a href=http://map.baidu.com name=tj_trmap class=mnav>地图</a> <a href=http://v.baidu.com name=tj_trvideo class=mnav>视频</a> <a href=http://tieba.baidu.com name=tj_trtieba class=mnav>贴吧</a> <noscript> <a href=http://www.baidu.com/bdorz/login.gif?login&amp;tpl=mn&amp;u=http%3A%2F%2Fwww.baidu.com%2f%3fbdorz_come%3d1 name=tj_login class=lb>登录</a> </noscript> <script>document.write(\'<a href="http://www.baidu.com/bdorz/login.gif?login&tpl=mn&u=\'+ encodeURIComponent(window.location.href+ (window.location.search === "" ? "?" : "&")+ "bdorz_come=1")+ \'" name="tj_login" class="lb">登录</a>\');\r\n                </script> <a href=//www.baidu.com/more/ name=tj_briicon class=bri style="display: block;">更多产品</a> </div> </div> </div> <div id=ftCon> <div id=ftConw> <p id=lh> <a href=http://home.baidu.com>关于百度</a> <a href=http://ir.baidu.com>About Baidu</a> </p> <p id=cp>&copy;2017&nbsp;Baidu&nbsp;<a href=http://www.baidu.com/duty/>使用百度前必读</a>&nbsp; <a href=http://jianyi.baidu.com/ class=cp-feedback>意见反馈</a>&nbsp;京ICP证030173号&nbsp; <img src=//www.baidu.com/img/gs.gif> </p> </div> </div> </div> </body> </html>\r\n'
>>> 
>>> # 这一次就能看见汉字的出现了
... 
>>> # 接下来我们试试状态码不是200
... # 通过不断的主动试错能加深对一门新技术的理解
... 
>>> # 比如,故意打错url试试  
...
>>> r = requests.get("http://www.fkbaidu.com") 
>>> r.status_code
503
>>> # 或者,我们试试访问某些"遗迹"
... 
>>> r = requests.get("https://www.github.com/breakwa11/shadowsocksr")
>>> r.status_code
404
>>> 
>>> # 更多的情况可以自己多尝试尝试
... # 网络连接有风险,异常处理很重要
... # 通过主动试错,来掌握常见的异常处理
... 
>>> exit()  # 结束程序运行
```

## 爬取网页的通用代码框架

> 网络连接有风险,异常处理很重要

既然**异常处理很重要**,那总得知道是有什么异常不是?

**`Requests库`的常见异常**

|            异常             |                    说明                     |
| :-------------------------: | :-----------------------------------------: |
| `requests.ConnectionError`  | 网络连接错误异常,如`DNS`查询失败/拒绝连接等 |
|    `requests.HTTPError`     |               `HTTP`错误异常                |
|   `requests.URLRequired`    |                `URL`缺失异常                |
| `requests.TooManyRedirects` |      超过最大重定向次数,产生重定向异常      |
|  `requests.ConnectTimeout`  |           连接远程服务器超时异常            |
|     `requests.Timeout`      |         请求`URL`超时,产生超时异常          |

`requests.ConnectTimeout`和`requests.Timeout`的区别:
- `Timeout`是指**从发出`URL`请求到获取整个网页内容**超时的异常
- `ConnectTimeout`**仅指与远程服务器连接**产生的超时异常

**`raise_for_status()方法`:**

回顾前面流程图,

> 我们在上文有介绍过这个流程图
> ```flow
> get=>start: requests.get()
> statu=>condition: r.status_code == 200
> op1=>operation: 将r.text转换为可读编码
> e1=>end: 进一步操作
> op2=>operation: 产生异常
> e2=>end: 进行调试
> get->statu(yes)->op1->e1
> get->statu(no)->op2->e2
> ```

我们需要在`status_code`为$200$的时候再进行下一步操作

而`raise_for_status()方法`就可以实现这个判断

如果`status_code`不是$200$,则产生异常`requesets.HTTPError`

了解了几个常见的异常后,我们就可以来分析这个**通用的代码框架**了

```python
import requests


def main():
    url = "https://www.baidu.com"
    print(get_HTML_text(url))


def get_HTML_text(url):
    try:
        r = requests.get(url, timeout=30)
        # 检测异常
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        # 异常处理
        return "产生异常!!!"


if __name__ == "__main__":
    main()

```

**这个代码框架就是脱胎于这个流程图**

抛出异常 处理异常

没有异常 继续干活

当然,并不是说爬虫代码就一定要按照上面的代码来写

这是一种**思路**

## `requests.request()方法`

> 在`requests的简单使用`处,我们有提到`Requests库`的$7$个常用方法
> |         方法         |                  说明                  |  `HTML`  |
> | :------------------: | :------------------------------------: | :------: |
> | `requests.request()` | 构造一个请求，支撑以下各方法的基础方法 |  $ALL$   |
> |   `requests.get()`   |        获取`HTML`网页的主要方法        |  `GET`   |
> |  `requests.head()`   |       获取`HTML`网页头信息的方法       |  `HEAD`  |
> |  `requests.post()`   |    向`HTML`网页提交`POST`请求的方法    |  `POST`  |
> |   `requests.put()`   |    向`HTML`网页提交`PUT`请求的方法     |  `PUT`   |
> |  `requests.patch()`  |      向`HTML`网页提交局部修改请求      | `PATCH`  |
> | `requsets.delete()`  |        向`HTML`页面提交删除请求        | `DELETE` |

> 在`从requests.get()方法看requests库`处,我们有提到:
> 
> **你甚至可以说`requests库`只有一个方法:`requests.request()`**

现在就来单独讲讲`requests.request()方法`

同样,我又跑了去找它的源代码

**源码是最好的说明书,官方文档其次**

然后,很幸运地,

我发现它是提供了接口的

下面这段是`requests/api.py`中的代码

```python
def request(method, url, **kwargs):
    """Constructs and sends a :class:`Request <Request>`.

    :param method: method for the new :class:`Request` object: ``GET``, ``OPTIONS``, ``HEAD``, ``POST``, ``PUT``, ``PATCH``, or ``DELETE``.
    :param url: URL for the new :class:`Request` object.
    :param params: (optional) Dictionary, list of tuples or bytes to send
        in the query string for the :class:`Request`.
    :param data: (optional) Dictionary, list of tuples, bytes, or file-like
        object to send in the body of the :class:`Request`.
    :param json: (optional) A JSON serializable Python object to send in the body of the :class:`Request`.
    :param headers: (optional) Dictionary of HTTP Headers to send with the :class:`Request`.
    :param cookies: (optional) Dict or CookieJar object to send with the :class:`Request`.
    :param files: (optional) Dictionary of ``'name': file-like-objects`` (or ``{'name': file-tuple}``) for multipart encoding upload.
        ``file-tuple`` can be a 2-tuple ``('filename', fileobj)``, 3-tuple ``('filename', fileobj, 'content_type')``
        or a 4-tuple ``('filename', fileobj, 'content_type', custom_headers)``, where ``'content-type'`` is a string
        defining the content type of the given file and ``custom_headers`` a dict-like object containing additional headers
        to add for the file.
    :param auth: (optional) Auth tuple to enable Basic/Digest/Custom HTTP Auth.
    :param timeout: (optional) How many seconds to wait for the server to send data
        before giving up, as a float, or a :ref:`(connect timeout, read
        timeout) <timeouts>` tuple.
    :type timeout: float or tuple
    :param allow_redirects: (optional) Boolean. Enable/disable GET/OPTIONS/POST/PUT/PATCH/DELETE/HEAD redirection. Defaults to ``True``.
    :type allow_redirects: bool
    :param proxies: (optional) Dictionary mapping protocol to the URL of the proxy.
    :param verify: (optional) Either a boolean, in which case it controls whether we verify
            the server's TLS certificate, or a string, in which case it must be a path
            to a CA bundle to use. Defaults to ``True``.
    :param stream: (optional) if ``False``, the response content will be immediately downloaded.
    :param cert: (optional) if String, path to ssl client cert file (.pem). If Tuple, ('cert', 'key') pair.
    :return: :class:`Response <Response>` object
    :rtype: requests.Response

    Usage::

      >>> import requests
      >>> req = requests.request('GET', 'https://httpbin.org/get')
      >>> req
      <Response [200]>
    """

    # By using the 'with' statement we are sure the session is closed, thus we
    # avoid leaving sockets open which can trigger a ResourceWarning in some
    # cases, and look like a memory leak in others.
    with sessions.Session() as session:
        return session.request(method=method, url=url, **kwargs)

```

同样的,我们在它的源代码中发现了它**十分详细**的使用说明

**我不想做翻译机**,

你已经是个成熟的程序员了,要学会自己翻译(**能不百度就别百度**)

那么我就用我的话**大致**说一遍吧!

从它的脑袋:`def request(method, url, **kwargs):`开始

#### `method`

> **method**: method for the new :class:`Request` object: "**GET**", "**OPTIONS**", "**HEAD**", "**POST**", "**PUT**", "**PATCH**", or "**DELETE**".

这个参数是用来构建一个`Request对象`的(就是提交一个请求)

负责决定**请求方式**

它的值一共有$7$个(不区分大小写,实践得出)
- "**GET**"
- "**OPTIONS**"
- "**HEAD**"
- "**POST**"
- "**PUT**"
- "**PATCH**"
- "**DELETE**"

与`HTML`分别对应(名字都一样,太贴心了)

#### `url`

> **url**: URL for the new :class:`Request` object.

而这个`url`则是决定你要向哪个网页发起请求

它的值就是目标网站的`url`

引用它的源码给出的例子:

```python
>>> import requests
>>> req = requests.request('GET', 'https://httpbin.org/get')
>>> req
<Response [200]>
```

这里的`'GET'`就是`method`

`'https://httpbin.org/get'`就是`url`

我们也看到:

`req`返回的是一个`Response对象`

这些上文都讲过了,就不赘述了

#### `**kwargs`

这个是可选参数,共$13$个:
- **params**
- **data**
- **json**
- **headers**
- **cookies**
- **files**
- **auth**
- **timeout**
- **allow_redirects**
- **proxies**
- **verify**
- **stream**
- **cert**

**`params`**

> **params**: (optional) Dictionary, list of tuples or bytes to send in the query string for the :class:`Request`.

它的值是字典,元组列表或字节序列(`Dictionary, list of tuples or bytes`)

功能是将它的值作为参数添加到`url`中

举个例子:

```python
>>> # 在python console中演示对params的使用
... 
>>> import requests
>>> 
>>> dic = {'wd': 'ShyButHandsome'}
>>> 
>>> r = requests.get("https://www.baidu.com/s", params = dic)  # 此处要显示指定params   
>>>                         
>>> r.url  # 这样就起到了在百度搜索"ShyButHandsome"的作用,后文还会再给出demo
'https://www.baidu.com/s?wd=ShyButHandsome'

```

**`data`**

> **data**: (optional) Dictionary, list of tuples, bytes, or file-like object to send in the body of the :class:`Request`.

它的值是字典,元组列表,字节序列或文件对象(`Dictionary, list of tuples, bytes, or file-like object`)

功能是向服务器提供/提交资源(可以实现登录的功能)

举个例子:

```python
>>> # 在python console中演示对params的使用
... 
>>> import requests
>>> 
>>> url = "http://httpbin.org/post" # 本来是想post百度的,但是会出错,这里是官方给的练手的地方
>>> dic = {'key': 'value'}
>>> r = requests.post(url, data = dic)
>>> r. text
'{
    "args": {}, 
    "data": "", 
    "files": {}, 
    "form": {
    "key": "value"  // 这里
  }, 
  "headers": {
    "Accept": "*/*", 
    "Accept-Encoding": "gzip, deflate", 
    "Content-Length": "9", 
    "Content-Type": "application/x-www-form-urlencoded", 
    "Host": "httpbin.org", 
    "User-Agent": "python-requests/2.23.0"
  }, 
  "json": null, 
  "url": "http://httpbin.org/post"
}
'

```

**`json`**

> **json**: (optional) A JSON serializable Python object to send in the body of the :class:`Request`.

它的值是`python对象`

功能是把`python对象`编码成`JSON`提交

我当时挺奇怪,这不是用`data`也能做吗?

是的,但`data`更加简单,你不用去`import json`

```python
>>> # 不导入json
...
>>> import requests
>>> url = "http://httpbin.org/post" 
>>> dic = {'key': 'value'}
>>> r = requests.post(url, json = dic)
>>> r.text
'{
    "args": {}, 
    "data": "{\\"key\\": \\"value\\"}", 
    "files": {}, 
    "form": {}, 
    "headers": {
    "Accept": "*/*", 
    "Accept-Encoding": "gzip, deflate", 
    "Content-Length": "16", 
    "Content-Type": "application/json", 
    "Host": "httpbin.org", 
    "User-Agent": "python-requests/2.23.0", 
  }, 
  "json": {
        "key": "value" // 这里
  }, 
  "url": "http://httpbin.org/post"
}
'
```

```python
>>> # 导入json
... 
>>> import json  # 这里
>>> import requests  
>>> url = "http://httpbin.org/post" 
>>> dic = {'key': 'value'}
>>> r = requests.post(url, data=json.dumps(dic))     # 这里
>>> r.text
'{
    "args": {}, 
    "data": "{\\"key\\": \\"value\\"}", 
    "files": {}, 
    "form": {}, 
    "headers": {
    "Accept": "*/*", 
    "Accept-Encoding": "gzip, deflate", 
    "Content-Length": "16", 
    "Host": "httpbin.org", 
    "User-Agent": "python-requests/2.23.0", 
  }, 
  "json": {
        "key": "value"  // 这里
  }, 
  "url": "http://httpbin.org/post"
}
'
```

**`headers`**

> **headers**: (optional) Dictionary of HTTP Headers to send with the :class:`Request`.

它的值为字典(`Dictionary`)

功能是自定义`HTTP`头(有些网站指定特定的浏览器才能访问,这种时候就可以通过修改`header`中的`user-agent`来模拟这种浏览器)

举个例子:

```python
>>> # 通过修改header中的user-agent模拟Chrome10
>>> import requests  
>>> url = "http://httpbin.org/post" 
>>> hd = {'user-agent': 'Chrome/10'}
>>> r = requests.post(url, headers = hd)         
>>> r.text
'{
    "args": {}, 
    "data": "", 
    "files": {}, 
    "form": {}, 
    "headers": {
    "Accept": "*/*", 
    "Accept-Encoding": "gzip, deflate", 
    "Content-Length": "0", 
    "Host": "httpbin.org", 
    "User-Agent": "Chrome/10",   // 这里
  }, 
  "json": null, 
  "url": "http://httpbin.org/post"
}
'

```

**`cookies`**

> **cookies**: (optional) Dict or CookieJar object to send with the :class:`Request`.

它的值是字典或`CookieJar`

功能是`Request`中的`cookie`

**`files`**

> **files**: (optional) Dictionary of ``'name': file-like-objects`` (or ``{'name': file-tuple}``) for multipart encoding upload.``file-tuple`` can be a 2-tuple ``('filename', fileobj)``, 3-tuple ``('filename', fileobj, 'content_type')``or a 4-tuple ``('filename', fileobj, 'content_type', custom_headers)``, where ``'content-type'`` is a string defining the content type of the given file and ``custom_headers`` a dict-like object containing additional headers to add for the file.

它的值是字典

功能是传输文件(可以实现向某一个连接提交某一个文件)

**`auth`**

> **auth**: (optional) Auth tuple to enable Basic/Digest/Custom HTTP Auth.

它的值是元组

支持`HTTP`认证功能

**`timeout`**

> **timeout**: (optional) How many seconds to wait for the server to send data before giving up, as a float, or a :ref:`(connect timeout, read timeout) <timeouts>` tuple.


它的值是浮点数或元组

功能是:如果连接时间超出给定参数,则抛出`timeout`异常

**`proxies`**

> **proxies**: (optional) Dictionary mapping protocol to the URL of the proxy.

它的值是字典

功能是设定访问代理服务器(可以增加登录认证)

能够有效的防止对爬虫的逆追踪

**`allow_redirects`**

> **allow_redirects**: (optional) Boolean. Enable/disable GET/OPTIONS/POST/PUT/PATCH/DELETE/HEAD redirection. Defaults to ``True``.

布尔类型,默认`True`

功能是重定向开关

**`stream`**

> **stream**: (optional) if ``False``, the response content will be immediately downloaded.

布尔类型,默认`True`

功能是获取内容立即下载开关

**`verify`**

> **verify**: (optional) Either a boolean, in which case it controls whether we verify the server's TLS certificate, or a string, in which case it must be a path to a CA bundle to use. Defaults to ``True``.

布尔类型,默认为`True`

功能是认证`SSL`证书开关

**`cert`**

> **cert**: (optional) if String, path to ssl client cert file (.pem). If Tuple, ('cert', 'key') pair.

它的值是字符串或元组类型

本地`SSL`证书路径

## 写在最后

其实不光是看官方文档,实践也很重要

不然,学得快,忘得也快

[requests的文档(有中文哒!)](https://requests.readthedocs.io/zh_CN/latest/)

