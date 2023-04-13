#include <iostream>
#include "triangle.h"
#include "line.h"
#include "shape.h"
#include "x11context.h"
#include "drawbase.h"
#include "gcontext.h"
#include "matrix.h"
using namespace std;

// Constructor
Image::Image()
{
    vector<Shape *> shapes;
}

// Copy Constructor
Image::Image(const Image &from)
{
    vector<Shape *> shapes = from;
}

// Destructor
