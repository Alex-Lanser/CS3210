#include <iostream>
#include "row.h"
using namespace std;

// parameterized constructor
Row::Row(int length)
{
	if (length <= 0)
	{
		throw std::out_of_range("The length of the row has to be greater than 0");
	}
	this->length = length; // this->length is making the length for the Row, while length is the length that is input
	row_data = new double[length];
	clear();
}

// copy constructor
Row::Row(const Row &from)
{
	length = from.length;
	row_data = new double[length];
	for (int i = 0; i < length; i++)
	{
		row_data[i] = from.row_data[i];
	}
}

// destructor
Row::~Row()
{
	delete[] row_data;
}

// access operator (const)
double Row::operator[](int column) const
{
	if (column < 0 || column >= length)
	{
		throw out_of_range("Column must be >= 0 and < length");
	}
	return row_data[column];
}

// access operator (non-const)
double &Row::operator[](int column)
{
	if (column < 0 || column >= length)
	{
		throw out_of_range("Column must be >= 0 and < length");
	}
	return row_data[column];
}

// assignment operator
Row &Row::operator=(const Row &rhs)
{
	if (this != &rhs)
	{
		length = rhs.length;
		delete[] row_data;
		row_data = new double[length];
		for (int i = 0; i < length; i++)
		{
			this->row_data[i] = rhs.row_data[i];
		}
	}
	return *this;
}

// clear row data
void Row::clear()
{
	for (int i = 0; i < length; i++)
	{
		row_data[i] = 0;
	}
}