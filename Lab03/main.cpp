#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix matrix1(3, 3);
	Matrix matrix2(3, 3);
	Matrix matrix3(2, 3);

	cout << "Matrix 1" << endl;
	double num = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			matrix1[i][j] = num;
			num += 1;
			cout << matrix1[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Matrix 2" << endl;
	num = 8;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			matrix2[i][j] = num;
			cout << matrix2[i][j] << " ";
			num -= 1;
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Matrix 3" << endl;
	num = 0;
	for (int i = 0; i < 2; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			matrix3[i][j] = num;
			num += 1;
			cout << matrix2[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	Matrix identity = Matrix::identity(3);
	cout << "Identity matrix" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			cout << identity[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Add same size matrix" << endl;
	Matrix matrixAdd(3, 3);
	matrixAdd = matrix1 + matrix2;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			cout << matrixAdd[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Add 2 different size matrices" << endl;
	try
	{
		matrixAdd = matrix1 + matrix3;
	}
	catch(...)
	{
		cout << "Caught adding 2 different sized matrices." << endl << endl;
	}

	cout << "Multiply 2 same size matrices" << endl;
	Matrix matrixMult(3, 3);
	matrixMult = matrix1 * matrix2;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			cout << matrixMult[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Multiply scalar multiple. Matrix * scalar" << endl;
	Matrix scalarMult1(3, 3);
	scalarMult1 = matrix1 * 4;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			cout << scalarMult1[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Multiply scalar multiple. Scalar * matrix" << endl;
	Matrix scalarMult2(3, 3);
	scalarMult2 = 4 * matrix1;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			cout << scalarMult2[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	return 0;
}
