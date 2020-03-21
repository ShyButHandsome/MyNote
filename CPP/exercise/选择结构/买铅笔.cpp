#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int needs;
	cin >> needs;

	int planA[2];
	int planB[2];
	int planC[2];

	cin >> planA[0] >> planA[1]
		>> planB[0] >> planB[1]
		>> planC[0] >> planC[0];

	int planA_cost = ceil(needs / planA[0]) * planA[1]
	int planB_cost = ceil(needs / planB[0]) * planB[1]
	int planC_cost = ceil(needs / planC[0]) * planC[1]

	cout << (min(min(planA_cost, planB_cost), planC_cost))
	
	return 0;
}
