#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	double a[3][3], b[3][3], c[2][3];

	double num = 0;
	cout << "Matrix A" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = num;
			cout << a[i][j] << " ";
			num += 1.001;
		}
		cout << "]" << endl;
	}
	cout << endl;

	num = 8;
	cout << "Matrix B" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = num;
			cout << b[i][j] << " ";
			num -= 1;
		}
		cout << "]" << endl;
	}
	cout << endl;

	num = 0;
	cout << "Matrix C" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = num;
			cout << c[i][j] << " ";
			num += 1;
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Add Matrices" << endl;
	double added[3][3];
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			added[i][j] = a[i][j] + b[i][j]; // not the_matrix[i][j]
			cout << added[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Identity" << endl;
	double identity[3][3];
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				identity[i][j] = 1;
			}
			else
			{
				identity[i][j] = 0;
			}
			cout << identity[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;

	cout << "Transponse" << endl;
	double transpose[3][2];
	for (int i = 0; i < 3; i++)
	{
		cout << "[ ";
		for (int j = 0; j < 2; j++)
		{
			transpose[j][i] = c[i][j];
			cout << transpose[i][j] << " ";
		}
		cout << "]" << endl;
	}
	return 0;
}
