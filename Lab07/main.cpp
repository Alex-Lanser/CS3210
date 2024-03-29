#include "x11context.h"
#include <unistd.h>
#include <iostream>
#include "mydrawing.h"
#include <cstring>
int main(void)
{
    // GraphicsContext *gc = new X11Context(1910, 1200, GraphicsContext::BLACK);
    GraphicsContext *gc = new X11Context(1000, 800, GraphicsContext::BLACK);
    gc->setColor(GraphicsContext::GREEN);
    // make a drawing
    MyDrawing md(gc->getWindowWidth(), gc->getWindowHeight());
    // start event loop - this function will return when X is clicked
    // on window
    gc->runLoop(&md);
    delete gc;
    return 0;
}