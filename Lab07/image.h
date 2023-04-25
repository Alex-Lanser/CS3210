#ifndef image_h
#define image_h

#include <iostream>
#include <vector>
#include "shape.h"
#include "matrix.h"
#include "line.h"
#include "triangle.h"
using namespace std;

class Image
{
public:
    Image( ); 
    Image(const Image &from);
    ~Image();
    void operator=(const Image &rhs);
    void addLine(int x0, int y0, int x1, int y1, unsigned int color);
    void addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color);
    void draw(GraphicsContext *gc);
    void erase();
    Image undoShape(Image im);

private:
    vector<Shape *> shapes;
    GraphicsContext *gc;
};


#endif