#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int roof_num;
	cin >> roof_num;
	
	double time = 0;
	for (int i = 0; i < roof_num; i++)
	{
		double x, y;
		int members;
		cin >> x >> y >> members;
		
		double distence = sqrt(x*x + y*y);
		time += distence * 2 / 50 + members * 1.5;
	}
	
	cout << ceil(time);
}
