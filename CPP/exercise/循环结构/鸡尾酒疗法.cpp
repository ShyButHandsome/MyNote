#include<bits/stdc++.h>
using namespace std;

int main()
{
	int amount;
	cin >> amount;

	int chicken_all, chicken_useful;
	cin >> chicken_all >> chicken_useful;

	double chicken = 1.0 * chicken_useful / chicken_all;

//    cout << chicken << endl;

	for (int i = 0; i < amount-1; i++)
	{
		int other_all, other_useful;
		cin >> other_all >> other_useful;

		double other = 1.0 * other_useful / other_all;

//		cout << other << endl;

		bool chicken_better = chicken - other > 0.05;
		bool other_better = other - chicken > 0.05;

//		cout << chicken_better << " " << other_better << endl;

		if (other_better)
		{
			cout << "better\n";
		}
		else if (chicken_better)
		{
			cout << "worse\n";
		}
		else if (!chicken_better & !other_better)
		{
			cout << "same\n";
		}
	}

	return 0;
}
