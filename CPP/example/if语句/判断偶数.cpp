// 输入一个整数，判断是否是偶数
#include<iostream>
using namespace std;

int main()
{
    long long get_int;
    cin >> get_int;

    bool is_even_number = !(get_int % 2);

    if (is_even_number)
    {
        cout << "Yes!";
    }
    else
    {
        cout << "No!";
    }
    
    return 0;
}