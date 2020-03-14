// 分别输出100内所有奇数偶数之和
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum_ood = 0, sum_even = 0;

    for (int odd = 1, even = 2; odd <= 99; odd += 2, even += 2)
    {
        sum_ood += odd;
        sum_even += even;
    }

    cout << sum_ood << " " << sum_even;
}