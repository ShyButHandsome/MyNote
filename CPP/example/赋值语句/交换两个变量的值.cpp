#include<iostream>
using namespace std;

int main()
{
	int a, b, temp;
	cout << "Input a, b\n";
	cin >> a >> b;

	temp = a;
	a = b;
	temp = a;

	cout << "Now, a = " << a << endl << "b = " << b;

	return 0;
}
