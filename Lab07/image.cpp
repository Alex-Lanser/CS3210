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
#include "viewcontext.h"
using namespace std;

// Constructor
Image::Image()
{
}

// Copy Constructor
Image::Image(const Image &from)
{
    for (int i = 0; i < from.shapes.size(); i++)
    {
        shapes.push_back(from.shapes[i]->clone());
    }
}

// Destructor
Image::~Image()
{
    erase();
}

void Image::operator=(const Image &rhs)
{
    erase();
    for (int i = 0; i < rhs.shapes.size(); i++)
    {
        shapes.push_back(rhs.shapes[i]->clone());
    }
}

// Add a line to the shapes container
void Image::addLine(int x0, int y0, int x1, int y1, unsigned int color)
{
    shapes.push_back(new Line(x0, y0, x1, y1, color));
}

// Add a triangle to the shapes container
void Image::addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color)
{
    shapes.push_back(new Triangle(x0, y0, x1, y1, x2, y2, color));
}

// Draw all lines/triangles in the shapes container
void Image::draw(GraphicsContext *gc, ViewContext *vc)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->draw(gc, vc);
    }
}

// Erase all shapes and return all dynamic memory
void Image::erase()
{
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
    shapes.clear();
}

Image Image::undoShape(Image im)
{
    im.shapes.pop_back();
    return im;
}