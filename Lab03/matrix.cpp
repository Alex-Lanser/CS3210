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
	the_matrix = new Row *[rows];
	for (int i = 0; i < rows; i++)
	{
		the_matrix[i] = new Row(cols);
	}
}

// Copy constructor
Matrix::Matrix(const Matrix &from)
{
	rows = from.rows;
	cols = from.cols;
	the_matrix = new Row *[rows];
	for (int i = 0; i < rows; i++)
	{
		the_matrix[i] = new Row(cols);
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = from[i][j];
		}
	}
}

// Destructor
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete the_matrix[i];
	}
	delete[] the_matrix;
}

// Assignment operator. Check row.cpp from Lab 2 to see more accurately how to do this.
Matrix &Matrix::operator=(const Matrix &rhs)
{
	rows = rhs.rows;
	cols = rhs.cols;
	for (int i = 0; i < rhs.rows; i++)
	{
		for (int j = 0; j < rhs.cols; j++)
		{
			(*this)[i][j] = rhs[i][j];
		}
	}
	return *this;
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
	return result;
}

// Matrix addition.
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
			result[i][j] = (*this)[i][j] + rhs[i][j]; // not the_matrix[i][j]
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
		for (int j = 0; j < rhs.cols; j++)
		{
			for (int k = 0; k < cols; k++)
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

// global insertion operator... ios_base
std::ostream &operator<<(std::ostream &os, const Matrix &rhs)
{
	os.precision(2);
	for (int i = 0; i < rhs.rows; i++)
	{
		cout << "[";
		for (int j = 0; j < rhs.cols; j++)
		{
			os << setw(4);
			os << rhs[i][j];
			os << setw(4);
		}
		os << "]" << endl;
	}

	return os;
}
