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
    myInt(int x) : i(x) // i(x) does the same thing as i = x; i(x) can be used if i is const while i = x cannot
    {
        // i = x;
    }
    myInt() : i(0)
    {
        // i = 0;
    }
    // named constructor
    myInt myIntOne()
    {
        return myInt(1);
    }
    myInt operator+(const myInt &rhs) const
    {
        cout << "operator+" << endl;
        myInt result(this->i + rhs.i);
        return result;
    }
    myInt operator+(const int &rhs) const
    {
        cout << "operator+ (int rhs)" << endl;
        myInt result(this->i + rhs);
        return result;
    }
    friend myInt operator+(const int &lhs, const myInt &rhs);
    friend ostream &operator<<(ostream &os, const myInt &rhs);

private:
    int i;
};

myInt operator+(const int &lhs, const myInt &rhs) 
{
    cout << "operator+ (int lhs)" << endl;
    return rhs + lhs;
}

ostream &operator<<(ostream &os, const myInt &rhs)
{
    os << rhs.i << " ";
    return os;
}
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


// Rule of 3 - Have all 3 or none: Destructor, Copy Constructor, Copy Assignment Operator