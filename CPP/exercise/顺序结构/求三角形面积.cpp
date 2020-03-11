// 给出三个点的坐标求三角形面积
#include <bits/stdc++.h>
using namespace std; 

int main()
{
	double a[2], b[2], c[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	
	double ab = sqrt(pow(abs(a[0] - b[0]), 2) + pow(abs(a[1] - b[1]), 2 ));
	double ac = sqrt(pow(abs(a[0] - c[0]), 2) + pow(abs(a[1] - c[1]), 2 ));
	double bc = sqrt(pow(abs(c[0] - b[0]), 2) + pow(abs(c[1] - b[1]), 2 ));
	
	double p = (ab + ac + bc) / 2.0;
	
    // 海伦-秦九韶公式
	printf("%0.2f", sqrt(p * (p - ab) * (p - ac) * (p - bc)));
	
	return 0;
} 