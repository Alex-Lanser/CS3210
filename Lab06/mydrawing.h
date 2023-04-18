#ifndef MYDRAWING_H
#define MYDRAWING_H
#include "drawbase.h"
#include "image.h"
// forward reference
class GraphicsContext;
class MyDrawing : public DrawingBase
{
public:
    MyDrawing();
    // we will override just these
    virtual void paint(GraphicsContext *gc);
    virtual void mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y);
    virtual void mouseButtonUp(GraphicsContext *gc, unsigned int button, int x, int y);
    virtual void mouseMove(GraphicsContext *gc, int x, int y);

private:
    Image im;
    // We will only support one "remembered" line
    int x0;
    int y0;
    int x1;
    int y1;
    bool dragging; // flag to know if we are dragging
    int mode;      // variable to keep track of drawing mode
    unsigned int color;
};
#endif
