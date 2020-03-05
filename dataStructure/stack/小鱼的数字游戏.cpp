// 题目描述：
/*
小鱼最近被要求参加一个数字游戏，要求它把看到的一串数字
（长度不一定，以0结束，最多不超过100个，数字不超过2^32-1），
记住了然后反着念出来(表示结束的数字0就不要念出来了)。
这对小鱼的那点记忆力来说实在是太难了，
你也不想想小鱼的整个脑袋才多大，
其中一部分还是好吃的肉！
所以请你帮小鱼编程解决这个问题。
*/

// 挑战：使用栈解决问题
// 分析：利用栈的后进先出特性，很容易就能做到倒序输出
#include<iostream>
using namespace std;

int reverse[100], top = 0;

void push()
{
    do{
        cin>>reverse[++top];
    }while(reverse[top]!=0);
}
void pop()
{
    //top-1：数组中已经含有，所以要-1 
    while(top-1){
            cout<<reverse[--top]<<" ";
    } 
}

int main()
{
    push();
    pop();    
    return 0;
}
// V1.0 AC