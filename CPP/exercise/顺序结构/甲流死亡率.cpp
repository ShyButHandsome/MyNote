#include<cstdio>

int main(void)
{
    int definite, death;
    scanf("%d%d", &definite, &death);
	
	double death_rate = 100.0 * death / definite;
    // 输出%
    printf("%0.3f%%", death_rate);
    
    return 0; 
}
// 1.%的输出
// 输出%要使用%%（这并不算是转义字符）
// %% 和转义字符其实是两个概念
// \ 是编译器的转义，% 是 printf 解释的参数

// 2.整数除法
// 两个整型相除结果也会是整型