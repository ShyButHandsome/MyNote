// 输入有的钱
// 4块、5块、6块的笔
// 笔要多，钱不能剩下
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int money;
    cin >> money;

    int four = money / 4;
    int mod = money % 4;

    int five = 0;
    int six = 0;
    switch(mod)
    {
        case 1:
            four--;
            five++;
        case 2:
            four--;
            six++;
        case 3:
            four -= 2;
            five++;
            six++;
    }
    cout << "four: " << four << "\nfive: " << five << "\nsix: " << six;
}