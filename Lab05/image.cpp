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

// Add a line to the shapes container
void Image::addLine(int x0, int y0, int x1, int y1, unsigned int color)
{
    Line line(x0, y0, x1, y1, color);
    shapes.push_back(&line);
}

// Add a triangle to the shapes container
void Image::addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color)
{
    Triangle triangle(x0, y0, x1, y1, x2, y2, color);
    shapes.push_back(&triangle);
}

// Draw all lines/triangles in the shapes container
void Image::draw(GraphicsContext *gc)
{

    for (int i = 0; i < shapes.size(); i++)
    {
        cout << "Got here" << endl;
        shapes[i]->draw(gc);
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