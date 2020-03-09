// C = 5 * (F - 32) / 9
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double fath;
    cin >> fath;

    double centigrade = 5 * (fath - 32) / 9;
    printf("%0.5f", centigrade);
}