//标准输入&输出
#include <iostream>
//不要漏写
using namespace std; 
//每月都增加300块钱
const int add = 300; 
//在妈妈那里存下来的钱
int mother[12];
//每个月的预算
int cost[12];
//每个月剩下的钱
int rest = 0;
//年终能的到的钱
double get = 0;
//程序开始
int main(void)
{
    //先将每个月的预算全部输入
    for (int k = 0; k < 12; k++) {
        cin >> cost[k];
    }
    //进行判断
    for (int i = 0; i < 12; i++) {
	//如果输入符合条件
        if (cost[i] <= 350 && cost[i] > 0) {
	    //如果钱足够
            if ((rest + add - cost[i]) >= 0) {
		//给妈妈
                mother[i] = (rest + add - cost[i]) / 100;
                mother[i] = mother[i] * 100;
	    //如果钱不够
            } else {
		//这个月给妈妈0元
                mother[i] = 0;
            }
            //减去给妈妈的钱
            rest -= mother[i];
	    //加上妈妈给的钱减去预算
            rest += (add - cost[i]);
            //如果会吃土
            if (rest < 0) {
		//记录下吃土的月份（i是从0开始计数，所以加1）
                int mudMonth = i + 1;
		//输出吃土的月份
                cout << mudMonth * (-1);
		//程序结束
                return 0;
            }
        //如果输入不符合条件 
        } else {
	    //程序结束并返回警告值
            return 1;
        }
    }
    //计算年终能的到的钱
    //将存在妈妈那里的钱加起来
    for (int j = 0; j < 12; j++) {
        get += mother[j];
    }
    //乘以1.2
    get = get * 1.2f;
    //加上12月剩下的钱
    get += rest;
    //输出得到的钱
    cout << get;
    //程序正常结束
    return 0;
}
