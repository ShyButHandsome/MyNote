#include <iostream>
#include <cstdio>

using namespace std; //不要漏写

int main(void)
{
	//将数据全部输入并储存 
	int need;
	cin >> need;
	int num[3]; 
	int mon[3];
	cin >> num[0] >> mon[0];
	cin >> num[1] >> mon[1];
	cin >> num[2] >> mon[2];
	//将每包的个数储存下来 
	int sn[2];
	sn[0] = num[0];
	sn[1] = num[1];
	sn[2] = num[2];
	//将每包的价钱储存下来
	int sm[2];
	sm[0] = mon[0];
	sm[1] = mon[1];
	sm[2] = mon[2];
	 
	
	//将三种方式所需的钱算出来 
	for(int i = 0 ; i < 99999999 ; i++) {
		num[0] += sn[0];
		mon[0] += sm[0];
		if(num[0] >= need){
			break;
		}
	}
	
	for(int k = 0 ; k < 99999999 ; k++) {
		num[1] += sn[1];
		mon[1] += sm[1];
		if(num[1] >= need){
			break;
		}
	}
	
	cout << endl;
	for(int j = 0 ; j < 99999999 ; j++) {
		num[2] += sn[2];
		mon[2] += sm[2];
		if(num[2] >= need){
			break;
		}
	}
	
	
	//比较结果 
	if(mon[0] <= mon[1] && mon[0] <= mon[2]){
		cout << mon[0];
	}else if(mon[1] <= mon[0] && mon[1] <= mon[2]){
		cout << mon[1];
	}else if(mon[2] <= mon[0] && mon[2] <= mon[1]){
		cout << mon[2];
	}else{
		cout << "wrrong";
	}
	
	return 0;
}
