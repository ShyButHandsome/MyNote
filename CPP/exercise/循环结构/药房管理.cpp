#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int total, person;
	cin >> total >> person;
	
	int count = 0;
	for (int i = 0; i < person; i++)
	{
		int each;
		cin >> each;
		if (total - each < 0)
		{
			count++;
			continue;
		}
		total -= each;
	}
	cout << count;
	return 0;
}
