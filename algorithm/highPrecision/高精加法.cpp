#include <bits/stdc++.h>

using namespace std;

void add(const char *input_a, const char *input_b);

const int MAXN = 233333;

// 差点被ab搞晕
char main_a[MAXN], main_b[MAXN];

int main(void)
{
    cin >> main_a >> main_b;

    add(main_a, main_b);

    // system("pause");

    return 0;
}

int add_a[MAXN], add_b[MAXN], sum[MAXN];

void add(const char *input_a, const char *input_b)
{

    // 计算长度，一会倒着放有用
    int lena = strlen(input_a),
        lenb = strlen(input_b);

    // 倒序，方便计算
    for (int i = 0; i < lena; i++)
        add_a[i] = input_a[lena - i - 1] - 48;
    for (int i = 0; i < lenb; i++)
        add_b[i] = input_b[lenb - i - 1] - 48;

    // 结果的长度
    int len = 0;
    // 进位
    int crray = 0;

    // 模拟竖式加法
    while (len < lena || len < lenb)
    {
        sum[len] = add_a[len] + add_b[len] + crray;

        // 如果不能进位，那么crray就会是0（整数除法，舍去小数）
        crray = sum[len] / 10;
        // 如果没有进位，sum < 10,值不会改变
        sum[len] %= 10;

        // 对下一次操作
        ++len;
    }

    // 处理最高进位，不输出前导零
    sum[len] = crray;
    // 如果最高进位是0,!取反
    if (!sum[len])
        len--;

    // 输出结果
    for (int i = len; i >= 0; i--)
        cout << sum[i];

    cout << endl;

    return;
}