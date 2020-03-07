// 两个变量交换，可以想象成一瓶酱油和一瓶醋进行交换，我们可以再拿一个空瓶子过来
// 将酱油倒入空瓶中 - 将醋倒入酱油瓶中 - 将空瓶（现在有酱油了）中的酱油倒入醋瓶中
// 接下来就是要用计算机语言将这个过程描述出来了
#include<iostream>
using namespace std;

int main()
{
	// 我们可以声明一个变量用于临时存放（空瓶），在这里我们就叫它temp（"临时"的意思）
	int a, b, temp;
	cout << "Input a, b\n";
	cin >> a >> b;

	// 将酱油倒入空瓶中
	temp = a;
	// 将醋倒入酱油瓶中
	a = b;
	// 将空瓶（现在有酱油了）中的酱油倒入醋瓶中
	temp = a;

	cout << "Now, a = " << a << endl << "b = " << b;

	return 0;
}
