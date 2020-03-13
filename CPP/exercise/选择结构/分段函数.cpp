// y= −x + 2.5;          0≤x<5
// y= 2 − 1.5(x−3)(x−3); 5≤x<10
// y= x/2 − 1.5;         10≤x<20
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x;
	cin >> x;
	
    // 这里的类型转换刚好
	int section = x / 5.0;

	double y = 0;
	switch(section)
	{
        // 5 * 一个[0,1]之间的数结果在[0,5]
		case 0:
			y = (-x) + 2.5;
			break;
		case 1:
			y = 2.0 - 1.5 * pow((x-3), 2);
			break;
			
		default:
			y = x / 2.0 - 1.5;
	}

	cout << setiosflags(ios::fixed) << setprecision(3) << y;
	
    return 0;
}