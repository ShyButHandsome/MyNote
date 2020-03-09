// turn an int to bool
// turn the bool to an int
#include<iostream>
using namespace std;

int main()
{
    int get_int;
    cin >> get_int;

    cout << static_cast<int>(static_cast<bool>(get_int));
}