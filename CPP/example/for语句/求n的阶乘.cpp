// 输入整数n
// 输出它的阶乘
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // int 略宽于 -2 * 10^9 ~ 2 * 10^9
    // long long 略窄于 -10^19 ~ 10^19
    long long fec = 1;

    for (int i = 1; i <= n; i++)
    {
        fec *= i;
    }
}