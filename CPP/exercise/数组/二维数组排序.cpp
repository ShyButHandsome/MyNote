#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    static int sum[16000][2];

    int count = 0;

    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            for (int k = 1; k <= c; ++k)
            {
                sum[count++][0] = i + j + k;
            }
        }
    }

    for (int i = 0; i < count; ++i)
    {
        if (sum[i][0])
        {
            for (int j = i + 1; j <= count; ++j)
            {
                if (sum[j][0] && sum[j][0] == sum[i][0])
                {
                    ++sum[i][1];
                    sum[j][0] = 0;
                }
            }
        }
    }

    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < count - i; ++j)
        {
            if (sum[j][1] < sum[j + 1][1])
            {
                swap(sum[j][0], sum[j + 1][0]);
                swap(sum[j][1], sum[j + 1][1]);
            }
            else if (sum[j][1] == sum[j + 1][1])
            {
                if (sum[j][0] > sum[j + 1][0])
                {
                    swap(sum[j][0], sum[j + 1][0]);
                    swap(sum[j][1], sum[j + 1][1]);
                }
            }
        }
    }

    cout << sum[0][0];

    return 0;
}