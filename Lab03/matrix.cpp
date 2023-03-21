#include "matrix.h"
#include <iomanip>
using namespace std;

// constructor
Matrix::Matrix(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		throw std::out_of_range("The rows and columns must be greater than 0");
	}
	this->rows = rows;
	this->cols = cols;
}

// Copy constructor
Matrix::Matrix(const Matrix &from)
{
	this->rows = from.rows;
	this->cols = from.cols;
	// this->the_matrix = from.the_matrix;
}

// Destructor
Matrix::~Matrix()
{
	delete[] the_matrix;
}

// Assignment operator
Matrix &Matrix::operator=(const Matrix &rhs)
{
	Matrix result(rhs.rows, rhs.cols);
	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			result[i][j] = rhs[i][j];
		}
	}
	return result;
}

// Named Constructor
Matrix Matrix::identity(unsigned int size)
{
	Matrix result(size, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				result[i][j] = 1;
			}
			else
			{
				result[i][j] = 0;
			}
		}
	}
}

// Matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const
{
	// Check size is correct
	if (rows != rhs.rows && cols != rhs.cols)
	{
		throw logic_error("Rows of both matrices and cols "
						  "of both matrices must be equal");
	}
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result[i][j] = (*this)[i][j]; // not the_matrix[i][j]
		}
	}
	return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const
{
	if (cols != rhs.rows)
	{
		throw logic_error("The cols of the first matrix "
						  "must be equal to the rows of the second matrix.");
	}
	Matrix result(rows, rhs.cols);
	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			for (int k = 0; k < rhs.cols; k++)
			{
				result[i][j] += (*this)[i][k] * rhs[k][j];
			}
		}
	}
	return result;
}

// Scalar multiplication
Matrix Matrix::operator*(const double scale) const
{
	Matrix result(this->rows, this->cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result[i][j] = ((*this)[i][j]) * scale;
		}
	}
	return result;
}

// global scalar multiplication
Matrix operator*(const double scale, const Matrix &rhs)
{
	Matrix result(rhs.rows, rhs.cols);
	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			result[i][j] = scale * rhs[i][j];
		}
	}
	return result;
}

// Transpose of a Matrix
Matrix Matrix::operator~() const
{
	Matrix result(this->cols, this->rows);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			result[j][i] = (*this)[i][j];
		}
	}
	return result;
}

// Clear Matrix
void Matrix::clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(*this)[i][j] = 0;
		}
	}
}

// Access Operators - non-const
Row &Matrix::operator[](unsigned int row)
{
	if (row < 0 || row >= rows)
	{
		throw out_of_range("Row cannot be less than 0 or "
						   "greater than the amount of rows in matrix");
	}
	return *(the_matrix[row]);
}

// Access Operators - const
Row Matrix::operator[](unsigned int row) const
{
	if (row < 0 || row >= rows)
	{
		throw out_of_range("Row cannot be less than 0 or "
						   "greater than the amount of rows in matrix");
	}
	return *(the_matrix[row]);
}

// global insertion operator
std::ostream &operator<<(std::ostream &os, const Matrix &rhs)
{
	// finish
}