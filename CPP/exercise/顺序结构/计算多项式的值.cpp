#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;

    printf("%0.7f", pow(x, 3) * a + pow(x, 2) * b + x * c + d);

    return 0;
}
// 输入假如用scanf的话要lf