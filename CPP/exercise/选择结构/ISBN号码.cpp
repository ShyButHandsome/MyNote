#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string isbn;
    cin >> isbn;

    int num[9];
    memset(num, 0, sizeof(num));

    int count = 0, result = 0;
    for (int i = 0; i < 11; i++)
    {
        if (isbn[i] != '-')
        {
            num[++count] = isbn[i] - '0';
            result += num[count] * count;
        }
    }

    result %= 11;

    if (result == 10)
        result = 'X';
    else
        result += '0';

    if (isbn[12] == result)
    {
        cout << "Right";
        return 0;
    }

    isbn[12] = result;

    cout << isbn;

    return 0;
}