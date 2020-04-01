#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int times;
	cin >> times;

	int for_how_long = 0;
	int long_max = for_how_long;
	for (int i = 0; i < times; i++)
	{
		int shou_suo, shu_zhang;
		cin >> shou_suo >> shu_zhang;
		if (shou_suo >= 90 && shou_suo <= 140 && shu_zhang >= 60 && shu_zhang <= 90)
		{
			for_how_long++;
			if (long_max < for_how_long)
				long_max = for_how_long;
		}
		else
		{
			for_how_long = 0;
		}
	}
	
	cout << long_max;
}
