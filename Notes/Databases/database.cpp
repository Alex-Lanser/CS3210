#include "database.h"
#include <iostream>

Database::Database(int size)
{
    cout << "constructor" << endl;
    if (size <= 0)
    {
        throw out_of_range("size must be >= 0");
    }
    this->size = size;
    data = new int[size];
}

Database::Database(const Database &from)
{
    cout << "copy constructor" << endl;
    this->size = from.size; // Can just be size = from.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        this->data[i] = from.data[i];
    }
}

// In destructor, just undo what is done in constructor
// When main returns, the destructor is called automatically
Database::~Database()
{
    cout << "destructor" << endl;
    delete[] data;
}

// Can use const functions with non const variables
void Database::print_first_data() const
{
    cout << data[0] << endl;
}

Database Database::operator=(const Database &rhs)
{
    if (this != &rhs)
    {
        cout << "operator=" << endl;
        size = rhs.size;
        delete[] data;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = rhs.data[i];
        }
    }
    return *this;
}

int Database::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index must be >= 0 and < size");
    }
    cout << "operator[]" << endl;
    return data[index];
}

int &Database::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index must be >= 0 and < size");
    }
    cout << "non-const operator[]" << endl;
    return data[index];
}

// To run with valgrind: just input valgrind ./main