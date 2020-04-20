#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    // 记得去掉system("pause")
    int m, n, r;
    cin >> m >> n;

    do
    {
        r = m % n;
        m = n;
        n = r;
    } while (r);
    

    // system("pause");
    return 0;
}