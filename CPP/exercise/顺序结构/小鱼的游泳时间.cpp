#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(void)
{

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int e, f;

    e = ((c * 60 + d) - (a * 60 + b)) / 60;
    f = ((c * 60 + d) - (a * 60 + b)) % 60;

    cout << e << " " << f;

    return 0;
}