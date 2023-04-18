#include "mydrawing.h"
#include "gcontext.h"
// Constructor
MyDrawing::MyDrawing()
{
    dragging = false;
    x0 = x1 = y0 = y1 = 0;
}
void MyDrawing::paint(GraphicsContext *gc)
{
    // The stored image should be drawn
}
void MyDrawing::mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y)
{
    x0 = x;
    y0 = y;
}
void MyDrawing::mouseButtonUp(GraphicsContext *gc, unsigned int button, int x, int y)
{
}
void MyDrawing::mouseMove(GraphicsContext *gc, int x, int y)
{
    gc->drawLine(x0, y0, x, y);
}
