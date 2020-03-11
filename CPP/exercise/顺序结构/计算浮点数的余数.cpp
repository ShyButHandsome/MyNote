// 输入两个双精度浮点数，输出它们的余数
// divisor = divident * k + mod 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    double divisor, dividend;
    cin >> divisor >> dividend;

    cout << divisor -  static_cast<int>(divisor / dividend) * dividend;
}