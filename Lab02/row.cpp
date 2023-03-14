#include <iostream>
#include "row.h"
using namespace std;

// parameterized constructor
Row::Row(int length)
{
	if (length <= 0)
	{
		throw std::out_of_range("The length has to be greater than 0");
	}
	this->length = length; // this->length is making the length for the Row, while length is the length that is input
	row_data = new double[length];
	clear();
}

// copy constructor
Row::Row(const Row &from)
{
	int length = from.length;
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
	// finish
	double result;
	return result;
}

// access operator (non-const)
double &Row::operator[](int column)
{
	// finish
	double result;
	return result;
}

// assignment operator
Row &Row::operator=(const Row &rhs)
{
	// finish
	Row result(1);
	return result;
}

// clear row data
void Row::clear()
{
	for (int i = 0; i < length; i++)
	{
		row_data[i] = 0;
	}
}