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
    virtual void keyDown(GraphicsContext *gc, unsigned int keycode);
    ~MyDrawing();
    void readFromFile(string filename);

private:
    Image im;
    Image copyIm;
    unsigned int color;
    ViewContext *vc;
    void rotateXClockwise(GraphicsContext *gc);
    void rotateXCounterclockwise(GraphicsContext *gc);
    void rotateYClockwise(GraphicsContext *gc);
    void rotateYCounterclockwise(GraphicsContext *gc);
    void scaleUp(GraphicsContext *gc);
    void scaleDown(GraphicsContext *gc);
    void translateUp(GraphicsContext *gc);
    void translateRight(GraphicsContext *gc);
    void translateDown(GraphicsContext *gc);
    void translateLeft(GraphicsContext *gc);
    void undoAll(GraphicsContext *gc, ViewContext *vc);

    Matrix coord0 = Matrix(4, 1);
    Matrix coord1 = Matrix(4, 1);
    Matrix coord2 = Matrix(4, 1);
};
#endif
