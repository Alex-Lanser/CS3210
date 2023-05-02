#include <iostream>
#include "triangle.h"
#include "shape.h"
#include "x11context.h"
#include "drawbase.h"
#include "gcontext.h"
#include "matrix.h"
#include "viewcontext.h"
using namespace std;

// Triangle constructor
Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color)
{
    this->coord0[0][0] = x0;
    this->coord0[1][0] = y0;
    this->coord0[2][0] = 0;
    this->coord0[3][0] = 1;

    this->coord1[0][0] = x1;
    this->coord1[1][0] = y1;
    this->coord1[2][0] = 0;
    this->coord1[3][0] = 1;

    this->coord2[0][0] = x2;
    this->coord2[1][0] = y2;
    this->coord2[2][0] = 0;
    this->coord2[3][0] = 1;

    this->color = color;
}

// Clone a triangle
Shape *Triangle::clone()
{
    return new Triangle(*this);
}

// Draw the triangle
void Triangle::draw(GraphicsContext *gc, ViewContext *vc)
{
    gc->setColor(color);
    Matrix point0 = vc->ModelToDevice(coord0);
    Matrix point1 = vc->ModelToDevice(coord1);
    Matrix point2 = vc->ModelToDevice(coord2);
    gc->drawLine(point0[0][0], point0[1][0], point1[0][0], point1[1][0]);
    gc->drawLine(point0[0][0], point0[1][0], point2[0][0], point2[1][0]);
    gc->drawLine(point1[0][0], point1[1][0], point2[0][0], point2[1][0]);
}