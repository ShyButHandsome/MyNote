#include<bits/stdc++.h>

using namespace std;

int recursion_write(int x)
{
    if (x < 0)
    { // 判负 + 输出负号 + 变原数为正数
        x = -x;
        putchar('-');
    }
    if (x > 9)
        recursion_write(x / 10); // 递归，将除最后一位外的其他部分放到递归中输出
    putchar(x % 10 + '0'); // 已经输出（递归）完 x 末位前的所有数字，输出末位
}

inline void loop_write(int x)
{
    static int sta[35];
    int top = 0;
    do
    {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48); // 48 是 '0'
}
