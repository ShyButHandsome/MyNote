#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int max_sum;
    cin >> max_sum;

    int sum = 0, count = 0;

    int now = 2;

    while (sum <= max_sum)
    {
        int find = 2;
        while (find <= sqrt(now) && now % find != 0)
            ++find;
        if (find > sqrt(now))
        {
            sum += now;
            if (sum > max_sum)
                break;
            cout << now << endl;
            count++;
        }
        now++;
    }

    cout << count;

    return 0;
}