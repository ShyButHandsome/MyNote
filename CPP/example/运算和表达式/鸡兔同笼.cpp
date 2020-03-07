// 已知头共30个，脚共90只，问鸡、兔各几只？
// 鸡兔同笼问题可以用二元一次方程来解决
// bird + rabbit = 30
// bird * 2 + rabbit * 4 = 90
// 可是如何用C++实现呢？
// 我们可以用循环来列出所有可能的数进行判断
// 符合条件就输出
// 但这种方法的本质只是‘穷举’，效率并不是很高，也不是很美观
#include<iostream>
using namespace std;

void optimization(int head, int foot);

int main()
{
    const int HEAD = 30;
    const int FOOT = 90;

    for (int bird = 1; bird <= 30; bird++)
    {
        int rabbit = HEAD - bird;
        if (bird * 2 + rabbit * 4 == FOOT)
        {
            cout << "There are " << bird << " birds and " << rabbit << " rabbits.\n" << endl;
        }
    }
    
    optimization(HEAD, FOOT);
    return 0;
}
// 优化如下（这种方案没想到）
// 用“极限”的思想求出鸡的个数，再求出兔的个数
// 不用循环
// 假如全都是兔子的话就会有4 * HEAD只脚（就是相当于给每只鸡多加了两只脚）
// 4 * HEAD - FOOT求出来的就是给所有鸡多加的脚
// 每只鸡多加两个，那/2就是鸡的数量了
// HEAD - bird 就是兔子的数量
// 这就是小学的做法啊
void optimization(int head, int foot)
{
    int bird  = (4 * head - foot) / 2;
    int rabbit = head - bird;

    cout << "There are " << bird << " birds and " << rabbit << " rabbits.\n" << endl;
}