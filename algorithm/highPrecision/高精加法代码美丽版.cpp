#include <iostream>

// EXIT_SUCCESS在stdlib库中
#include <cstdlib>

// strlen函数需要cstring库
#include <cstring>

using namespace std;

// 500+6防止数组越界
const int LENGTH_LIMIT = 5e2 + 6;

// char表示的整数 减去一个‘0’就可以得到响应整数的ascii
const int INT_CHANGER = '0';

// 个位数不能超过10
const int SINGLE_LIMIT = 10;

char stringA[LENGTH_LIMIT];
char stringB[LENGTH_LIMIT];

int invertedA[LENGTH_LIMIT];
int invertedB[LENGTH_LIMIT];
int sum[LENGTH_LIMIT];

int main(void)
{

    cin >> stringA >> stringB;

    // 倒叙储存
    int lengthA = strlen(stringA);
    for (int i = 0; i < lengthA; i++)
    {
        // 由于strlen返回的长度是符合正常思维(从1开始)
        // 但我们是从0开始,所以要额外 - 1
        invertedA[i] = stringA[lengthA - i - 1] - INT_CHANGER;
    }

    int lenghtB = strlen(stringB);
    for (int i = 0; i < lenghtB; i++)
    {
        invertedB[i] = stringB[lenghtB - i - 1] - INT_CHANGER;
    }

    // 和的最大长度是a,b最大值+1
    const int MAX_LENGTH = ((lengthA < lenghtB) ? lenghtB : lengthA) + 1;

    // 进位
    int carry = 0;

    // 模拟计算
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        // 对应位相加
        sum[i] = invertedA[i] + invertedB[i] + carry;
        // 记录下进位
        carry = sum[i] / SINGLE_LIMIT;
        // 进位操作
        sum[i] %= SINGLE_LIMIT;
    }

    // 这里length选择放在循环外,因为两个循环都会用到它
    // +1是因为strlen返回的数组长度是从1开始计数的
    int length = MAX_LENGTH;

    // 删除前导零(确定数字实际长度)
    for (length; length > 0; length--)
    {
        // 这里取length>0,因为
        // 如果删到最后一位就必须得保留,不管它是不是0

        if (sum[length] == 0)
        {
            // 接着处理下一位
            continue;
        }
        else
        {
            // 如果遇到一位非零就说明前导零删干净了
            // 接着删就会删去数字中的0了
            break;
        }
    }

    // 正序输出
    for (length; length >= 0; length--)
    {
        cout << sum[length];
    }

    // 额外输出一个换行
    cout << endl;

    // EXIT_SUCCESS means 0
    return EXIT_SUCCESS;
}
