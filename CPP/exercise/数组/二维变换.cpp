// P1205缝缝补补
#include <bits/stdc++.h>

using namespace std;

bool R90(int n);
bool R180(int n);
bool R270(int n);
bool mirror(int n);
bool group(int n);
bool clone(int n);
bool check(int n);

char before[10][10];
char run[10][10];
char after[10][10];

char fuck[10][10];

// main
int main(void)
{
    // input
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> before[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> after[i][j];

    // which way
    if (R90(n))
        cout << 1;
    else if (R180(n))
        cout << 2;
    else if (R270(n))
        cout << 3;
    else if (mirror(n))
        cout << 4;
    else if (group(n))
        cout << 5;
    else if (clone(n) && check(n))
        cout << 6;
    else
        cout << 7;

    return 0;
}

// clone
bool clone(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[i][j] = before[i][j];

    return true;
}

// do check
bool check(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (run[i][j] == after[i][j])
                continue;
            else
                return false;
        }
    return true;
}

// rotate 90 radius
bool R90(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[j][n - i - 1] = before[i][j];
    return check(n);
}

// rotate 180 radius
bool R180(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[n - i - 1][n - j - 1] = before[i][j];
    return check(n);
}

// rotate 270 radius
bool R270(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[n - j - 1][i] = before[i][j];
    return check(n);
}

// mirror
bool mirror(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[i][n - j - 1] = before[i][j];

    return check(n);
}

void fk(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fuck[i][j] = run[i][j];
}

// rotate 90 radius
bool fR90(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[j][n - i - 1] = fuck[i][j];
    return check(n);
}

// rotate 180 radius
bool fR180(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[n - i - 1][n - j - 1] = fuck[i][j];
    return check(n);
}

// rotate 270 radius
bool fR270(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[n - j - 1][i] = fuck[i][j];
    return check(n);
}

// after mirror, rotate
bool group(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            run[i][n - j - 1] = before[i][j];

    fk(n);

    if (fR90(n) || fR180(n) || fR270(n))
        return true;
    else
        return false;
}
