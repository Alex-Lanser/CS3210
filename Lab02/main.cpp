#include <iostream>
#include "row.h"
using namespace std;
int main()
{
    // test constructor
    Row R1(3);
    cout << "R1: " << R1[0] << " " << R1[1] << " " << R1[2] << endl;
    // test setting row data
    R1[0] = 0;
    R1[1] = 1;
    R1[2] = 2;
    Row R3(4);
    R3[0] = 3;
    R3[1] = 4;
    R3[2] = 5;
    R3[3] = 6;
    cout << "R1: " << R1[0] << " " << R1[1] << " " << R1[2] << endl;
    // test copy constructor
    Row R2(R1);
    cout << "R2: " << R2[0] << " " << R2[1] << " " << R2[2] << endl;
    // test assignment operator when left side is larger

    cout << "R3: " << R3[0] << " " << R3[1] << " " << R3[2] << endl;
    R3 = R2;
    cout << "R3: " << R3[0] << " " << R3[1] << " " << R3[2] << endl;
    // test self assignment
    R3 = R3;
    cout << "R3: " << R3[0] << " " << R3[1] << " " << R3[2] << endl;
    // test assignment operator when right side is larger
    Row R4(4);
    R4[0] = 7;
    R4[1] = 8;
    R4[2] = 9;
    R4[3] = 10;
    cout << "R4: " << R4[0] << " " << R4[1] << " " << R4[2] << " " << R4[3] << endl;
    R3 = R4;
    cout << "R3: " << R3[0] << " " << R3[1] << " " << R3[2] << " " << R3[3] << endl;
    cout << "R4: " << R4[0] << " " << R4[1] << " " << R4[2] << " " << R4[3] << endl;
    // test const access operator
    const Row R5 = R1;
    cout << "R5: " << R5[0] << " " << R5[1] << " " << R5[2] << endl;
    // test clear function
    R1.clear();
    cout << "R1: " << R1[0] << " " << R1[1] << " " << R1[2] << endl;
    // test constructor is throwing exceptions correctly
    try
    {
        Row R6(0);
    }
    catch (...)
    {
        cout << "Row of length 0 failed" << endl;
    }
    try
    {
        Row R7(-4);
    }
    catch (...)
    {
        cout << "Row of length -4 failed" << endl;
    }
    // test access operator is throwing exceptions correctly
    try
    {
        R1[-1];
    }
    catch (...)
    {
        cout << "column = -1 failed" << endl;
    }
    try
    {
        R1[3];
    }
    catch (...)
    {
        cout << "column = length failed" << endl;
    }
    return 0;
}