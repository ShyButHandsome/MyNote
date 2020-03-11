#include<iostream>

using namespace std;



int main(void){
	int getK = 0;
	
	int num = 1; 
	
	cin >> getK;
	
	for(int i = 0; i >= 0; i++){
		num = num + (1/i);	
		if(num > getK){
			cout << i;
			return 0;
		}
	}
	return 1;
}
