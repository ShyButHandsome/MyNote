#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int div, divd, n, the_bit;
    cin >> div >> divd >> n;

    for (int i = 0; i <= n; ++i)
    {
        // 整数除法
        the_bit = div / divd;
        // 模拟
        div = div < divd ? (div * 10) : (div % divd) * 10;
    }

    cout << the_bit << endl;

    // system("pause");
    return 0;
}