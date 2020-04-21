#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // int
    int c = 0, lastc = c;
    static int change[15];
    int count_all = 0, count = 0;

    bool the_first_is_zero = true;

    // 用了赋值的话EOF会类型转换为-1
    while ((c = getchar()) != -1)
    {
        if (c == '\r' || c == '\n')
            continue;

        c -= '0';

        if (the_first_is_zero)
        {
            if (c == 0)
                // 以后不再进来
                the_first_is_zero = false;
            else
            {
                change[count++] = 0;
                lastc = 1;
                the_first_is_zero = false;
            }
        }

        if (c == lastc)
        {
            change[count]++;
            count_all++;
        }
        else
        {
            change[++count]++;
            count_all++;
        }
        lastc = c;
    }

    cout << sqrt(count_all) << " ";

    for (int i = 0; i <= count; ++i)
        cout << change[i] << " ";

    return 0;
}
