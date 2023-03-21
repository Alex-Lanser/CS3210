#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	double a[3][3], b[3][3];

	double num = 0;
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
	for (int i = 2; i >= 0; i--)
	{
		cout << "[ ";
		for (int j = 2; j >= 0; j--)
		{
			b[i][j] = num;
			cout << b[i][j] << " ";
			num -= 1;
		}
		cout << "]" << endl;
	}

	
	return 0;
}
