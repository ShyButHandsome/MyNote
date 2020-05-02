// @will7101
#include <cstdio>

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int a, b, x, y, d;
    scanf("%d%d", &a, &b);
    d = exgcd(a, b, x, y);
    printf("gcd(a, b) = %d\n", d);
    printf("x = %d, y = %d\n", x, y);
}
