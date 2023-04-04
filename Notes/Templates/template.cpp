#include <iostream>
using namespace std;

template <typename T> // T can be an int, double, float, etc.

T add(T lhs, T rhs)
{
    return lhs + rhs;
}

int main()
{
    int a = 1;
    int b = 2;
    cout << add<int>(a, b) << endl;

    double i = 1;
    double j = 2;
    cout << add<double>(i, j) << endl;
    
    return 0;
}