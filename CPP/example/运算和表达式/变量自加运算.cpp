// 通过几个实例来体会自加运算不同位置的影响
#include<iostream>
using namespace std;

int main()
{
    int x = 7, y = 8;
    int z1 = y - (x++);
    int z2 = y - (++x);
    
    cout << "z1 = " << z1 << "\n" << "z2 = " << z2;
}