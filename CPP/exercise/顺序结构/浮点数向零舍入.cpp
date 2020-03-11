// Input an float number
// 负数向上，正数向下（说白了都是舍去小数部分）
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double input;
    cin >> input;

    cout << static_cast<int>(input);
}

// 强制类型转换可以实现 