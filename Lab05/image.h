#ifndef image_h
#define image_h

#include <iostream>
#include "shape.h"
#include "matrix.h"
#include "line.h"
#include "triangle.h"
using namespace std;

class Image
{
public:
    Image::Image(vector<Shape *> newShapes); 
    Image::Image(const Image &from);
    Image::~Image();
    Image &Image::operator=(const Image &rhs);
    void addLine(int x0, int y0, int x1, int y1, unsigned int color);
    void addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color);
    void draw(GraphicsContext *gc);
    void erase();

private:
    Image::clone();
    vector<Shape *> shapes;
};


#endif