// 输入两个整数radius&high
// 喝20L水才不渴
#include <bits/stdc++.h>
using namespace std; 

int main()
{
	const double PI = 3.1415926;
	double high, radius;
	cin >> high >> radius;
	
	double volume = PI * radius * radius * high / 1000.0;

	cout << ceil(20.0 / volume);
	
	return 0;
} 