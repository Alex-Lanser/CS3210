#include <iostream>
#include "line.h"
#include "shape.h"
#include "matrix.h"
using namespace std;

Line::Line(int x0, int y0, int x1, int y1, unsigned int color)
{
    
}

Shape *Line::clone()
{
    return new Line(*this);
}

void Line::clone(GraphicsContext *gc)
{
}