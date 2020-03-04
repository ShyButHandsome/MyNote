// description:
/*
Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. 
More precisely... rewrite small numbers from input to output. 
Stop processing input after reading in the number 42. 
All numbers at input are integers of one or two digits.
*/
// 其实我也看不懂，不过题目有翻译：
// 从输入读取数字并输出，每行一个，直到读到42停止。

// challenge: use recursion to solve problem
#include<iostream>
using namespace std;

void recursion()
{
    int input = 0;
    cin >> input;
    if (input == 42)
    {
        return;
    }
    cout << input << endl;
    recursion();
}

int main()
{
    recursion();
    return 0;
}
// V1.0 AC