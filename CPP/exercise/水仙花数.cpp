#include <iostream>

using namespace std;

int main(void)
{
	
	int a , b , c;
	
	
	for(int i = 100;i < 1000; i++)
	{
		a = i / 100;
		b = (i - a * 100) / 10;
		c = (i - b*10) % 100;
		
		if(a * 100 + b * 10 +c == a*a*a + b*b*b + c*c*c)
			cout << i << endl;
	}
	
	return 0;
}
