#include<iostream>

using namespace std;

int main(void)
{
    int dvs , dvde , qtt , mod;
    //putin divisor and dividend
    cin >> dvs >> dvde ;
    //quotients
    qtt = dvs / dvde;
    //mod
    mod = dvs % dvde;
    //putout quotiens and mod
    cout << qtt << " " << mod;

    return 0;
}