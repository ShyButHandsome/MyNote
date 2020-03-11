#include <bits/stdc++.h>
using namespace std; 

int main()
{
	long total, per_h, hour;
	cin >> total >> per_h >> hour;
	
	long eat = ceil(double(hour) / double(per_h));
	
	cout << (((total - eat) > 0) ? (total - eat) : 0) ;
	
	return 0;
} 
// 多次提交出错：
// 全吃完了就没了，不能输出负数
// "<<"的运算符优先级高于 "? :"