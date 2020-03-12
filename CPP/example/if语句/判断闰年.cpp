// 输入一个年份，判断是否闰年
#include<iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter the year";
    cin >> year;

    bool is_leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

    if (is_leap_year)
    {
        cout << "is leap year";
    }
    else
    {
        cout << "is not a leap year";
    }
    
    return 0;
}