#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int amount;
	cin >> amount;

	int count = 0;
	for (int i = 0; i < amount; i++)
	{
		int the_num;
		cin >> the_num;
		int thou = the_num / 1000;
		int hum = the_num % 1000 / 100;
		int ten = the_num % 100 / 10;
		int sig = the_num % 10;
//		cout << thou << hum << ten << sig << endl;
		if ((sig - thou - hum - ten) > 0)
			count++;
	}
	
	cout << count;
}
