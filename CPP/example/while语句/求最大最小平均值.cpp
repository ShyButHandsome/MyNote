#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int temp, min, max, sum;
    cin >> temp;
    max = min = sum = temp;

    // 上面已经有一次输入了
    int count = 1;

    while (cin >> temp && ++count)
    {
        sum += temp;
        min = temp < min ? temp : min;
        max = temp > max ? temp : max;
    }

    cout << min << " " << max << " " << setiosflags(ios::fixed) << setprecision(3) << 1.0 * sum / count << endl;

    system("pause");
    return 0;
}