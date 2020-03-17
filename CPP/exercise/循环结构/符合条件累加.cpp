#include<bits/stdc++.h>
using namespace std;

int main()
{
	int begin, end;
	cin >> begin >> end;
	
	int sum = 0;
	for (int num = begin; num <= end; num++)
	{
		bool is_divisible = (num % 17 == 0);
		sum += (is_divisible ? num : 0);
	}
	
	cout << sum;

	return 0;
}