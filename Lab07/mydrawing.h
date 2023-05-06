#ifndef MYDRAWING_H
#define MYDRAWING_H
#include "drawbase.h"
#include "image.h"
#include "viewcontext.h"
#include "matrix.h"

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
    void readFromFile(string filename, GraphicsContext *gc);

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
    void rotateClockwise(GraphicsContext *gc);
    void rotateCounterclockwise(GraphicsContext *gc);
    void scaleUp(GraphicsContext *gc);
    void scaleDown(GraphicsContext *gc);
    void translateUp(GraphicsContext *gc);
    void translateRight(GraphicsContext *gc);
    void translateDown(GraphicsContext *gc);
    void translateLeft(GraphicsContext *gc);

    Matrix coord0 = Matrix(4, 1);
    Matrix coord1 = Matrix(4, 1);
    Matrix coord2 = Matrix(4, 1);
};
#endif
