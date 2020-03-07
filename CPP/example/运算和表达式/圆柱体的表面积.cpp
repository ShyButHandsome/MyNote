// 输入圆柱体的底面半径R和高H，输出圆柱体的表面积
// 分析：圆柱体的表面积 = 上底面积（半径为R的圆round） + 下底面积（半径为R的圆round） + 侧面积（长为底面圆周长2*PI*R，宽为高的长方形rectangle）
// 已经给出了R和H，PI是一个常量，那么只要分别计算出两者（两个圆一样）的面积，再加起来，就是最终的圆柱体表面积了
#include<iostream>
// pow()
#include<cmath>
// 0.000
#include<cstdio>

using namespace std;

const double PI = 3.14159265;

int main()
{
    double radius, high;
    cout << "Input radius & high:\n";
    cin >> radius >> high;

    double round = PI * pow(radius, 2);
    double circumference = 2 * PI * radius;
    double rectangle = circumference * high;
    double surface = rectangle + round * 2;

    // cout  << surface;
    printf("So, the surface is %0.3lf", surface);

    return 0;
}