// 输入三个整数，按从大到小的顺序输出
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 保证a >= b
    if(a < b)
    {
        swap(a, b);
    }
    // 保证a >= c
    if(a < c)
    {
        swap(a, c);
    }
    // 保证b >= c
    if(b < c)
    {
        swap(b, c);
    }
    cout << a << " " << b << " " << c;

    return 0;
}
// 注意：这里的if前面不能加else
// 因为if-else链中只会有一个语句块被执行(像switch-case一样)
// 但是可以嵌套if-else