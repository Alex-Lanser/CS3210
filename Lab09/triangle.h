#ifndef triangle_h
#define triangle_h

#include <iostream>
#include "shape.h"
#include "matrix.h"
#include "viewcontext.h"
using namespace std;

class Triangle : public Shape
{
public:
    Triangle(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, unsigned int color);
    Shape *clone();
    void draw(GraphicsContext *gc, ViewContext *vc);

private:
    Matrix coord0 = Matrix(4, 1);
    Matrix coord1 = Matrix(4, 1);
    Matrix coord2 = Matrix(4, 1);
};


#endif