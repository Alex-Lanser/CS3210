#include <iostream> // System file
#include "math.h"   // Own header file
using namespace std;

// To compile, must do g++ -o main main.cpp math.cpp
// To run, must do ./main

// To compile without linking, just do g++ -c main.cpp
// This created multiple .o files
// To run the executable, then link the .o files
// g++ -o main main.o math.o
// This is better than linking right away when you have a very large project and you make one small change in one file,
// then you do not have to recompile it all. This is what makefiles do

int main()
{
    cout << add(3, 4) << endl;
    return 0;
}