// 输出100内正整数和
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }

    cout << sum;
}