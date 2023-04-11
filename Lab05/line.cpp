#include <iostream>
#include "line.h"
#include "shape.h"
#include "x11context.h"
#include "drawbase.h"
#include "gcontext.h"
#include "matrix.h"
using namespace std;

Line::Line(int x0, int y0, int x1, int y1, unsigned int color)
{

}

Shape *Line::clone()
{
    return new Line(*this);
}

void draw(GraphicsContext *)
{
    
}