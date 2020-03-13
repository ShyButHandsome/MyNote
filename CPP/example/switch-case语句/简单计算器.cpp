// 前两个数为操作数 后面接运算符
// 仅支持加减乘除
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    char op;
    cin >> op;

    switch(op)
    {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                cerr << "Divided by zero!";
                break;
            }
            cout << num1 / num2;
            break;

        default:
            cout << "Invalid operrator!";
    }
}