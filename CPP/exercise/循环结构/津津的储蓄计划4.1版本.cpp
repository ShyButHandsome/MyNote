#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int mother = 0;
	int have = 0;
	const int ADD = 300;
	int cost = 0;
	for (int i = 0; i < 12; i++)
	{
		cin >> cost;
		have += ADD;
		if (have < cost)
		{
			cout << "-" << i + 1;
			return 0;
		}
		have -= cost;
		if (have > 100)
		{
			mother += have / 100 * 100;
			have -= have / 100 * 100;
		}
	}
	
	double money = mother * 1.2 + have;
	cout << money;
	return 0;
}
