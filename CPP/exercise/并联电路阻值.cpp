// R = 1 / (1/r1 + 1/r2)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double small_first, small_second;
    cin >> small_first >> small_second;

    double big = 1.0 / (1.0 / small_first + 1.0/ small_second);

    printf("%0.2f", big);
}