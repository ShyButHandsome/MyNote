#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;

    int r = m % n;

    while (r)
    {
        m = n;
        n = r;
        r = m % n;
    }

    cout << n << endl;

    system("pause");

    return 0;
}