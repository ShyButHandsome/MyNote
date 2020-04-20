#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // 记得去掉system("pause")
    static int a[10][10];

    int n;
    cin >> n;

    int x = 0, y = 0, count = a[x][y] = 1;

    while (count < n * n)
    {
        while (y + 1 < n && !a[x][y + 1])
            a[x][++y] = ++count;
        while (x + 1 < n && !a[x + 1][y])
            a[++x][y] = ++count;
        while (y - 1 >= 0 && !a[x][y - 1])
            a[x][--y] = ++count;
        while (x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = ++count;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] < 10)
                cout << "  " << a[i][j];
            else
                cout << " " << a[i][j];
        }
        cout << endl;
    }

    system("pause");
    return 0;
}