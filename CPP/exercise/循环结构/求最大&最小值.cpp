#include<bits/stdc++.h>
using namespace std;

int main()
{
	int max_val = 0;
    // min_val要取大一点，不然没法更新值
	int min_val = 1000;
	int each = 0;
	
    //  不断迭代
	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
  		cin >> each;
		max_val = max(max_val, each);
		min_val = min(min_val, each);
	}

	cout << max_val - min_val;
	
	return 0;
}