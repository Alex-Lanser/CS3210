#include "matrix.h"
#include<iomanip>
using namespace std;

// constructor
Matrix::Matrix(int rows, int cols){
	// finish
 }
 
// Copy constructor
Matrix::Matrix(const Matrix& from){
	// finish
}

// Destructor
Matrix::~Matrix(){
	// finish
}
 
// Assignment operator
Matrix& Matrix::operator=(const Matrix& rhs){
	// finish
}	
 
// Named Constructor 
Matrix Matrix::identity(unsigned int size){
	// finish
}	
		
// Matrix addition
Matrix Matrix::operator+(const Matrix& rhs) const{
	// finish
}
 
// Matrix multiplication 
Matrix Matrix::operator*(const Matrix& rhs) const{
	// finish
}
 
// Scalar multiplication
Matrix Matrix::operator*(const double scale) const{
	Matrix result(this->rows, this->cols);
	// finish
	return result;
}

// Transpose of a Matrix
Matrix Matrix::operator~() const{
	Matrix result(this->rows, this->cols);
	// finish
	return result;
}
 
// Clear Matrix
void Matrix::clear(){
	// finish
}
  
// Access Operators - non-const
Row& Matrix::operator[](unsigned int row){
	// finish
}
 
// Access Operators - const
Row Matrix::operator[](unsigned int row) const{
	// finish
}

// global insertion operator
std::ostream& operator<<(std::ostream& os, const Matrix& rhs){
	// finish
}	

// global scalar multiplication
Matrix operator*(const double scale, const Matrix& rhs){
	// finish
}
