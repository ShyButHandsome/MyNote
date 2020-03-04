/*
题目描述
津津上初中了。妈妈认为津津应该更加用功学习，所以津津除了上学之外，还要参加妈妈为她报名的各科复习班。另外每周妈妈还会送她去学习朗诵、舞蹈和钢琴。但是津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。假设津津不会因为其它事不高兴，并且她的不高兴不会持续到第二天。请你帮忙检查一下津津下周的日程安排，看看下周她会不会不高兴；如果会的话，哪天最不高兴。

输入格式
输入包括77行数据，分别表示周一到周日的日程安排。每行包括两个小于1010的非负整数，用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。

输出格式
一个数字。如果不会不高兴则输出00，如果会则输出最不高兴的是周几（用1, 2, 3, 4, 5, 6, 71,2,3,4,5,6,7分别表示周一，周二，周三，周四，周五，周六，周日）。如果有两天或两天以上不高兴的程度相当，则输出时间最靠前的一天。

输入输出样例
输入 #1复制
5 3
6 2
7 2
5 3
5 4
0 4
0 6
输出 #1复制
3
说明/提示
noip2004普及组第1题
*/
/*
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(void)
{

 	int Mon[2] ,Tue[2] ,Wend[2] ,Thur[2] ,Fri[2] ,Sat[2] ,Sun[2];
	
	cin >> Mon[0] >> Mon[1];
	cin >> Tue[0] >> Tue[1];
	cin >> Wend[0]>> Wend[1];
	cin >> Thur[0]>> Thur[1];
	cin >> Fri[0] >> Fri[1];
	cin >> Sat[0] >> Sat[1];
	cin >> Sun[0] >> Sun[1];
	
	int a , b , c , d ,e ,f ,g;

	a= Mon[0] + Mon[1]
	b= Tue[0] + Tue[1]
	c= Wend[0]+ Wend[1]
	d= Thur[0]+ Thur[1]
 	e= Fri[0] +Fri[1]
	f= Sat[0] + Sat[1]
	g= Sun[0] + Sun[1]
	
	if(a<8&&b<8&&c<8&&d<8&&e<8&&f<8&&g<8)
		{cout <<0;}
	else
	
	
	
	
	return 0;
}
*/
//写的屎一样，写不下去

//一段很好的代码，如下
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main ()
{
    int a,b,s,max=0,i,day=0;  //a,b是我们津津（以下简称JJ）每天上课时间，s意为sum是上课时间之和 
    for (i=1;i<8;i++)   // i为循环变量，day是JJ一周最不高兴的一天 
      {
        cin>>a>>b;    //输入a,b 
        s=a+b;   //计算一天的上课时间 
        if ((s>max)&&(s>8)) max=s,day=i;  //在超过8小时且比之前几天都大的s时，将s赋给最大值，并记录下JJ的这天 
      }
    cout<<day; //由于day初值是0，所以如果JJ一周都开心就输出0 
    return 0;             
}
