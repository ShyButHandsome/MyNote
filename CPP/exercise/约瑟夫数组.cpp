#include <iostream>

using namespace std;

int main(void)
{
	
	bool deta[101];
	int all , out;
	
	for(int i = 0; i < 100; i++) deta[i] = false;                                //初始化布尔数组 
	
	cout << "How many people?\n";
	cin >> all;                                                                  //总共人数 
	cout << "Which one?\n";
	cin >> out;                                                                  //出圈位置 
	
	int f = 0, t = 0 , counter = 0;
	
	do
	{
		++t;
		if(t == all +1) t = 1;                                                   //构成环状 
		if(deta[t] == false)++counter;                                           // 下一个 
		if(counter == out)                                                       //到了出圈位置 
		{
			counter = 0;                                                        //初始化计数器 
			deta[t] = true;                                                     // 
			cout << t;	
			++f;
		};
		
			
	}while(counter != all);
	
	
	return 0;
}
