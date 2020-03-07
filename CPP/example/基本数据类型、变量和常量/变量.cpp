// 从键盘上输入整数并将其显示出来
// 并通过在不同位置输出该变量的值
// 以及对其重新赋值
// 来体会变量的特点
#include<iostream>
using namespace std;

// 在函数外声明
int outside;

int main()
{
    cout << "Outside: " << outside << endl;

    // 在函数内声明, 且不进行初始化
    int inside;
    cout << "Inside: " << inside << endl;

    // 在函数内声明并初始化
    int first = 0;
    cout << "The first ini number: " << first << endl;
    int second(0);
    cout << "The second ini number: " << second << endl;
    int list_right{1};
    cout << "list_ini right: " << list_right << endl;
    int list_wrrong{1.5};
    cout << "list_ini wrrong(1.5): " << list_wrrong << endl;

    // 赋值
    cout << "Input_ini(inside): ";
    cin >> inside;
    cout << "So it's: " << inside << endl;

    // 再次赋值
    inside = 666;
    cout << "ini(inside) again: " << inside << endl;

    return  0;
}