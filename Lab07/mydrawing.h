#ifndef MYDRAWING_H
#define MYDRAWING_H
#include "drawbase.h"
#include "image.h"
#include "viewcontext.h"

// forward reference
class GraphicsContext;
class MyDrawing : public DrawingBase
{
public:
    MyDrawing(int width, int height);
    // we will override just these
    virtual void paint(GraphicsContext *gc);
    virtual void mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y);
    virtual void keyDown(GraphicsContext *gc, unsigned int keycode);
    ~MyDrawing();

private:
    Image im;
    Image copyIm;
    // We will only support one "remembered" line
    int x0;
    int y0;
    int x1;
    int y1;
    int numClicks;
    int mode;      // 0 == line, 1 == triangle
    unsigned int color;
    void undoShape(GraphicsContext *gc);
    ViewContext *vc;

};
#endif
