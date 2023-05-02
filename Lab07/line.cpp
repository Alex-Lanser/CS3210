#include <iostream>
#include "line.h"
#include "shape.h"
#include "x11context.h"
#include "drawbase.h"
#include "gcontext.h"
#include "matrix.h"
#include "viewcontext.h"
using namespace std;

// Line constructor
Line::Line(int x0, int y0, int x1, int y1, unsigned int color)
{
    this->coord0[0][0] = x0;
    this->coord0[1][0] = y0;
    this->coord0[2][0] = 0;
    this->coord0[3][0] = 1;

    this->coord1[0][0] = x1;
    this->coord1[1][0] = y1;
    this->coord1[2][0] = 0;
    this->coord1[3][0] = 1;

    this->color = color;
}

// Clone a line
Shape *Line::clone()
{
    return new Line(*this);
}

// Draw the line
void Line::draw(GraphicsContext *gc, ViewContext *vc)
{
    gc->setColor(color);
    Matrix point0 = vc->ModelToDevice(coord0);
    Matrix point1 = vc->ModelToDevice(coord1);
    gc->drawLine(point0[0][0], point0[1][0], point1[0][0], point1[1][0]);
}