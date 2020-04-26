// n ≤ 10 ^ 6 O(nlogN)
// q ≤ 10 ^ 9 int
// m ≤ 10 ^ 5
#include <bits/stdc++.h>

using namespace std;

// 函数原型
int bsearch(int target, int arrlen);
bool check(int mid, int target);

const int MAXN = 1e6 + 6;

// 10^6的数据，要开全局数组，全局默认初始化为0
int a[MAXN];

int main(void)
{
    // n是数组长度，m是查询次数
    int n, m;
    cin >> n >> m;

    // 输入
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target = 0;

    // 查询m次
    for (int i = 0; i < m; i++)
    {
        cin >> target;
        int ans = bsearch(target, n);
        cout << (ans == -1 ? ans : ans + 1) << " ";
    }

    cout << endl;

    return 0;
}

int bsearch(int target, int arrlen)
{
    int ans = -1;

    int left = 0;
    int right = arrlen;
    int mid = ans;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        // 如果target在左边（包括等于）
        if (check(mid, target))
            // 等于的话right依然会不断向左，而target在[left,right]之间（闭区间）
            // 当right不断向左直到等于left时依旧==target（再向左就小于target了）
            // left就是第一个出现的target（此时left==right==mid）
            // 如果还没到left就找到了target第一次出现，left就会开始向右移动，知道left==right==mid（一样的道理）
            right = mid;
        // 如果target在右边
        else
            left = mid + 1;
    }

    // 如果遍历了整个数组都没有找到target（也就是说没有a[mid]==target)
    // 我们不知道循环出来是什么情况，所以要判断一下
    return a[left] == target ? (ans = left) : ans;
}

bool check(int mid, int target)
{
    if (target <= a[mid])
        return true;
    else
        return false;
}