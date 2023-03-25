#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix matrix1(3, 3);
	Matrix matrix2(3, 3);
	Matrix matrix3(2, 3);
	Matrix matrix4(3, 2);

	cout << "Matrix 1" << endl;
	double num = 0;
	for (int i = 0; i < 3; i++) // Matrix1 Population
	{
		for (int j = 0; j < 3; j++)
		{
			matrix1[i][j] = num;
			num += 1;
		}
	}
	cout << matrix1 << endl;

	cout << "Matrix 2" << endl;
	num = 8;
	for (int i = 0; i < 3; i++) // Matrix2 Population
	{
		for (int j = 0; j < 3; j++)
		{
			matrix2[i][j] = num;
			num -= 1;
		}
	}
	cout << matrix2 << endl;

	cout << "Matrix 3" << endl;
	num = 0;
	for (int i = 0; i < 2; i++) // Matrix3 Population
	{
		for (int j = 0; j < 3; j++)
		{
			matrix3[i][j] = num;
			num += 1;
		}
	}
	cout << matrix3 << endl;

	cout << "Matrix 4" << endl;
	num = 5;
	for (int i = 0; i < 3; i++) // Matrix4 Population
	{
		for (int j = 0; j < 2; j++)
		{
			matrix4[i][j] = num;
			num -= 1;
		}
	}
	cout << matrix4 << endl;

	cout << "Identity matrix" << endl;
	Matrix identity = Matrix::identity(3);
	cout << identity << endl;

	cout << "Transpose of a 3x3 matrix (Matrix 1)" << endl;
	Matrix transpose1 = ~matrix1;
	cout << transpose1 << endl;

	cout << "Transpose of a 2x3 matrix (Matrix 3)" << endl;
	Matrix transpose2 = ~matrix3;
	cout << transpose2 << endl;

	cout << "Add same size matrix" << endl;
	Matrix matrixAdd(3, 3);
	matrixAdd = matrix1 + matrix2;
	cout << matrixAdd << endl;

	cout << "Add 2 different size matrices" << endl;
	try
	{
		matrixAdd = matrix1 + matrix3;
	}
	catch (...)
	{
		cout << "Caught adding 2 different sized matrices." << endl
			 << endl;
	}

	cout << "Multiply 2 same size matrices" << endl;
	Matrix matrixMult3x3(3, 3);
	matrixMult3x3 = matrix1 * matrix2;
	cout << matrixMult3x3 << endl;

	cout << "Multiply 2 different sized matrices properly (2x3)*(3x2)" << endl;
	Matrix matrixMult2x2(2, 2); // matrix3 * matrix4
	matrixMult2x2 = matrix3 * matrix4;
	cout << matrixMult2x2 << endl;

	cout << "Multiply 2 different sized matrices properly (3x2)*(2x3)" << endl;
	matrixMult3x3 = matrix4 * matrix3;
	cout << matrixMult3x3 << endl;

	cout << "Multiply 2 different sized matrices improperly (3x3)*(2x3)" << endl;
	try
	{
		matrixMult3x3 = matrix1 * matrix3;
	}
	catch (...)
	{
		cout << "Caught multiplying improper sized matrices" << endl
			 << endl;
	}

	cout << "Multiply scalar multiple. Matrix * scalar" << endl;
	Matrix scalarMult1(3, 3);
	scalarMult1 = matrix1 * 4;
	cout << scalarMult1 << endl;

	cout << "Multiply scalar multiple. Scalar * matrix" << endl;
	Matrix scalarMult2(3, 3);
	scalarMult2 = 4 * matrix1;
	cout << scalarMult2 << endl;

	cout << "Clear a matrix (Matrix 2)" << endl;
	matrix2.clear();
	cout << matrix2 << endl;

	return 0;
}
