#include <iostream>
#include "image.h"
#include "gcontext.h"

GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);
int main()
{
    Image image;
    image.addLine(0, 0, 10, 10, 0xff000);
    image.addTriangle(100, 100, 110, 110, 90, 90, 0x00ff00);
    image.draw(gc);
    return 0;
}