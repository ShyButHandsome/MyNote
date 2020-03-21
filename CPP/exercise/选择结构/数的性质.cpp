// 性质一：偶数
// 性质二：大于4且不大于12
// 小A都喜欢
// Uim有一种符合就喜欢
// 八尾勇喜欢只符合一种性质的
// 正妹都不喜欢
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

	bool nature_a = (num % 2 == 0);
	bool nature_b = ((num > 4 ) && (num <= 12));

    bool small_a = nature_a & nature_b;
    bool Uim = nature_a | nature_b;
	bool eight_weiyong = nature_a ^ nature_b;
    // 这里一开始写成了!small_a,但不是那样
    // Uim只要有一个条件为真就为真
    // 正妹刚好相反，只有两个都不为真时才为真
	bool right_girl = !Uim;

	cout << small_a << " " << Uim << " " << eight_weiyong << " " << right_girl;
	return 0;
}