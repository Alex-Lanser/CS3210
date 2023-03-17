#include <iostream>
#include "database.h"
using namespace std;

void f(Database D)
{
}

Database g()
{
    Database D(10);
    return D;
}

class myInt
{
public:
    int i;
    myInt operator+(myInt rhs)
    {
        cout << "operator+" << endl;
        myInt result;
        result.i = this->i + rhs.i;
        return result;
    }
};

int main()
{
    Database D1(3);
    Database D2(2);
    D1 = D2; // D1.operator=(D2);
    D1.data[0] = 7;
    cout << D1[0] << endl; // D1.operator[](0)

    // myInt my1;
    // my1.i = 1;
    // myInt my2;
    // my2.i = 2;
    // myInt my3 = my1.operator+(my2);
    // cout << my3.i << endl;

    // const double = 4;
    // const double *xp = &x;
    // const double &xr = x; // Not just double &xr = x;

    // const Database D1(5); // If const, then print_first_data() must be a const function as well
    // D1.print_first_data();
    return 0;
};