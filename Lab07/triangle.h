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
    Triangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color);
    Shape *clone();
    void draw(GraphicsContext *gc, ViewContext *vc);

private:
    Matrix coord0 = Matrix(4, 1);
    Matrix coord1 = Matrix(4, 1);
    Matrix coord2 = Matrix(4, 1);
};


#endif