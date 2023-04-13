#include <iostream>
#include "line.h"
#include "shape.h"
#include "x11context.h"
#include "drawbase.h"
#include "gcontext.h"
#include "matrix.h"
using namespace std;

Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color)
{
    this->coord0[0][0] = x0;
    this->coord0[0][1] = y0;
    this->coord0[0][2] = 0;
    this->coord0[0][3] = 1;

    this->coord1[0][0] = x1;
    this->coord1[0][1] = y1;
    this->coord1[0][2] = 0;
    this->coord1[0][3] = 1;

    this->coord2[0][0] = x2;
    this->coord2[0][1] = y2;
    this->coord2[0][2] = 0;
    this->coord2[0][3] = 1;

    this->color = color;
}

Shape *Triangle::clone()
{
    return new Triangle(*this);
}

void Triangle::draw(GraphicsContext *gc)
{
    gc->setColor(color);
    gc->drawLine(coord0[0][0], coord0[0][1], coord1[0][0], coord1[0][1]);
    gc->drawLine(coord0[0][0], coord0[0][1], coord2[0][0], coord2[0][1]);
    gc->drawLine(coord1[0][0], coord1[0][1], coord2[0][0], coord2[0][1]);
}