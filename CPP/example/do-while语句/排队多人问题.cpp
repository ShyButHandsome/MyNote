/*
* 每行[1,6]人，多出一人
* 每行7人，刚好
*/
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    // 记得去掉system("pause")
    int x = 0;
    bool yes;
    do
    {
        yes = true;
        x += 7;
        if (x % 2 != 1)
            yes = false;
        if (x % 3 != 1)
            yes = false;
        if (x % 4 != 1)
            yes = false;
        if (x % 5 != 1)
            yes = false;
        if (x % 6 != 1)
            yes = false;

    } while (!yes);
    

    // system("pause");
    return 0;
}