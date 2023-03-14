#include<iostream>
#include "row.h"
using namespace std;

// parameterized constructor
Row::Row(int length){
	// finish
}

// copy constructor
Row::Row(const Row& from){
	// finish
}

// destructor
Row::~Row(){
	//finish
}

// access operator (const)
double Row::operator[](int column) const{
	//finish
	double result;
	return result;
}

// access operator (non-const)
double& Row::operator[](int column){
	//finish
	double result;
	return result;
}

// assignment operator
Row& Row::operator= (const Row& rhs){
	//finish
	Row result(1);
	return result;
}

// clear row data
void Row::clear(){
	//finish
}