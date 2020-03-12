// 给出外多边形边数
// 求所有对角线的焦点
// 任意三条对角线不会相交于一点
// 即每个点一定是由两条不同的对角线相交形成的
// 对于任意一个顶点，他会发出n-3条对角线
// 相邻顶点所发出的对角线会与该顶点形成一个首项为n-3公差为-1的等差数列
// 形成的交点对于这两条对角线来说是唯一的，
// 因为是线段，没有方向，所以最后结果应该要/2

#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;

    unsigned long long a_1 = n - 3;
    const int D = -1;
    cout << ((a_1*n + a_1*(n-1)*D*n)*n)/4;
}