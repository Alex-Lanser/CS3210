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
Image::Image(vector<Shape *> newShapes)
{
    shapes = newShapes;
}

// Copy Constructor
Image::Image(vector<Shape *> const &from)
{
    for (int i = 0; i < from.size(); i++)
    {
        shapes[i].push_back(from[i]->clone());
    }
}

// Destructor
Image::~Image()
{
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
    shapes.clear();
}

