#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > c)
		swap(a, c);

    bool is_tria = (a + b > c) && (b - a < c);

    if (is_tria)
    {
		if (a*a + b*b == c*c)
			cout << "Right triangle" << endl;
		else if (a*a + b*b > c*c)
			cout << "Acute triangle" << endl;
		else
			cout << "Obtuse triangle" << endl;
  		if (a == b)
		{
			cout << "Isosceles triangle" << endl;
			if (b == c)
				cout << "Equilateral triangle" << endl;
		}
	}
	else
		cout << "Not triangle" << endl;

    return 0;
}
