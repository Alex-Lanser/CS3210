#ifndef line_h
#define line_h

#include <iostream>
#include "shape.h"
#include "matrix.h"
using namespace std;

class Line : public Shape
{
public:
    Line(int x0, int y0, int x1, int y1, unsigned int color);
    Shape *clone();
    void draw(GraphicsContext *gc);

private:
    Matrix coord = Matrix(4, 1);
};

#endif