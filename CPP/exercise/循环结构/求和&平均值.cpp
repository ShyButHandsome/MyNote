#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;
	
	int sum = 0;
	int each = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> each;
		sum += each;
	}
	
	double average = 1.0*sum / num;
	
	cout << sum << " " << setiosflags(ios::fixed) << setprecision(5) << average;
	
	return 0;
}