#include <iostream>
#include <vector>
#include "triangle.h"
#include "line.h"
#include "shape.h"
#include "x11context.h"
#include "drawbase.h"
#include "gcontext.h"
#include "matrix.h"
#include "image.h"
using namespace std;


GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);
// Constructor
Image::Image()
{
}

// Copy Constructor
Image::Image(const Image &from)
{
    for (int i = 0; i < from.size(); i++)
    {
        shapes[i].push_back(from.shapes[i]->clone());
    }
}

// Destructor
Image::~Image()
{
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
    shapes.clear();
}

void Image::operator=(const Image &rhs)
{
    for (int i = 0; i < rhs.shapes.size(); i++)
    {
        shapes[i] = rhs.shapes[i];
    }
}

void Image::addLine(int x0, int y0, int x1, int y1, unsigned int color)
{
    Line line(x0, y0, x1, y1, color);
    line.draw(gc);
}

void Image::addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color)
{
    Triangle triangle(x0, y0, x1, y1, x2, y2, color);
    triangle.draw(gc);
}

void Image::draw(GraphicsContext *gc)
{

}

void Image::erase()
{

}