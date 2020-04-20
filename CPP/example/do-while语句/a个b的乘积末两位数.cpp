#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    // 记得去掉system("pause")
    int a = 1, t = 0;
    do
    {
        ++t;
        a = (a * 92) % 100;
    } while (t != 1992);

    cout << a << endl;

    // system("pause");
    return 0;
}