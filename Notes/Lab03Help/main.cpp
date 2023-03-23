#include <iostream>
using namespace std;

class Row
{
public:
    double *row_data;
    int length;
    Row() : length(1)
    {
        cout << "default constructor" << endl;
        row_data = new double[length];
    }
    Row(int length) : length(length)
    {
        cout << "paramater constructor" << endl;
        row_data = new double[length];
    }

    double &operator[](int col)
    {
        return row_data[col];
    }
};

int main()
{
    // Row R(3); // 1 row object with length 3
    // Row R[3]; // 3 row objects with default constructor
    // Row R[3] = {1, 2, 3}; // 3 row objects with 3 different lengths
    // Row *RP; // No constructor calls
    // Row *RP = new Row[4]; // 4 row objects with default constructor
    // Row **the_matrix = new Row *[3]; // Does not call any constructors
    // the_matrix[0] = new Row(2);
    // the_matrix[1] = new Row(2);
    // the_matrix[2] = new Row(2);

    Row *RP0 = the_matrix[0];
    Row *RP1 = the_matrix[1];
    Row *RP2 = the_matrix[2];

    Row R0 = *RP0;
    Row R1 = *RP1;
    Row R2 = *RP2;

    R1[1] = 5;

    cout << R1[1] << endl;

    // (*RP1)[1] = 5; // Changes R1[1]
    // (*(the_matrix[1]))[1]; // (*(the_matrix[1])) is R1.

    // matrix
    Row **the_matrix;
    // constructor
    the_matrix = new Row *[rows];
    for (int i = 0; i < rows; i++)
    {
        the_matrix[i] = new Row(cols);
    }

    // destructor
    for (int i = 0; i < rows; i++)
    {
        delete the_matrix[i]; // Not deleting an array, deleting individual object, so not delete[].
    }
    delete[] the_matrix;

    
    int *A = new int;
    int *B = new int[3];
    *A = 3;
    *B = 4;
    // cout << A[0] << " " << B[0] << endl;
    A[1] = 5; // Bad because A[1] is not allocated
    B[1] = 6;
    // cout << A[1] << " " << B[1] << endl;
    return 0;
}