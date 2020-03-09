// Input radius
// Output circumference, diameter and area
#include<bits/stdc++.h>
using namespace std;

int main()
{
    const double PI = 3.14159;

    double radius;
    cin >> radius;

    double diameter = 2 * radius;
    double circumference = 2 * PI * radius;
    double area = PI * pow(radius, 2);

    printf("%0.4f %0.4f %0.4f", diameter, circumference, area); 
}