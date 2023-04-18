#include <iostream>
#include <unistd.h>
#include "image.h"
#include "gcontext.h"

int main()
{
    GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);
    // Create new image
    Image image;
    // Add line to image
    image.addLine(10, 10, 30, 30, GraphicsContext::BLUE);
    image.draw(gc);
    // Add triangle to image
    image.addTriangle(300, 300, 200, 200, 250, 100, GraphicsContext::GREEN);
    image.draw(gc);
    sleep(2);
    // Create copy of image
    Image imageCopy(image);
    // Add line to the copy
    imageCopy.addLine(30, 30, 100, 110, GraphicsContext::RED);
    imageCopy.draw(gc);
    sleep(2);
    // Make a copy of the copy
    Image imageCopy2 = imageCopy;
    // Add triangle to new copy
    imageCopy2.addTriangle(100, 100, 150, 250, 200, 300, GraphicsContext::YELLOW);
    imageCopy2.draw(gc);
    sleep(2);
    // Add line to new copy
    imageCopy2.addLine(400, 300, 400, 400, GraphicsContext::WHITE);
    // Erase original image and image copy
    image.erase();
    imageCopy.erase();
    // Clear all the drawings
    gc->clear();
    // Redraw the images in the newest copy
    imageCopy2.draw(gc);
    sleep(2);
    // Erase the copy
    imageCopy2.erase();
    // Clear the drawings
    gc->clear();
    sleep(1);

    delete gc;
    return 0;
}