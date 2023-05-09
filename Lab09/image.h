#ifndef image_h
#define image_h

#include <iostream>
#include <vector>
#include "shape.h"
#include "matrix.h"
#include "line.h"
#include "triangle.h"
#include "viewcontext.h"
using namespace std;

class Image
{
public:
    Image( ); 
    Image(const Image &from);
    ~Image();
    void operator=(const Image &rhs);
    void addLine(int x0, int y0, int x1, int y1, unsigned int color);
    void addTriangle(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, unsigned int color);
    void draw(GraphicsContext *gc, ViewContext *vc);
    void erase();
    Image undoShape(Image im);

private:
    vector<Shape *> shapes;
    vector<Shape *> originalShapes;
    GraphicsContext *gc;
};


#endif