#include "mydrawing.h"
#include "gcontext.h"

// Constructor
MyDrawing::MyDrawing()
{
    cout << "COLORS:" << endl;
    cout << "1: White" << endl;
    cout << "2: Black" << endl;
    cout << "3: Red" << endl;
    cout << "4: Yellow" << endl;
    cout << "5: Blue" << endl;
    cout << "6: Green" << endl;
    cout << "Press T to draw a triangle." << endl;
    cout << "Press L to draw a line." << endl;
    cout << "To undo previous shape, press backspace." << endl;
    numClicks = 0; // Track the number of clicks
    mode = 0;      // Default mode is line
    numShapes = 0;
    color = GraphicsContext::GREEN;
}
void MyDrawing::paint(GraphicsContext *gc)
{
    im.draw(gc);
}
void MyDrawing::mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y)
{
    if (mode == 0) // Line
    {
        if (numClicks == 0)
        {
            x0 = x;
            y0 = y;
            numClicks++;
        }
        else // 2nd click
        {
            gc->drawLine(x0, y0, x, y);
            im.addLine(x0, y0, x, y, color);
            numClicks = 0;
            numShapes++;
        }
    }
    else if (mode == 1) // Triangle
    {
        if (numClicks == 0)
        {
            x0 = x;
            y0 = y;
            numClicks++;
        }
        else if (numClicks == 1) // 2nd click
        {
            x1 = x;
            y1 = y;
            numClicks++;
        }
        else // 3rd click
        {
            gc->drawLine(x0, y0, x1, y1);
            gc->drawLine(x0, y0, x, y);
            gc->drawLine(x1, y1, x, y);
            im.addTriangle(x0, y0, x1, y1, x, y, color);
            numClicks = 0;
            numShapes++;
        }
    }
}
void MyDrawing::undoShape(GraphicsContext *gc)
{
    gc->clear();
    im = im.undoShape(im);
    paint(gc);
}
void MyDrawing::keyDown(GraphicsContext *gc, unsigned int keycode)
{
    switch (keycode)
    {
    case 0x31:
        gc->setColor(GraphicsContext::WHITE);
        color = GraphicsContext::WHITE;
        break;
    case 0x32:
        gc->setColor(GraphicsContext::BLACK);
        color = GraphicsContext::BLACK;
        break;
    case 0x33:
        gc->setColor(GraphicsContext::RED);
        color = GraphicsContext::RED;
        break;
    case 0x34:
        gc->setColor(GraphicsContext::YELLOW);
        color = GraphicsContext::YELLOW;
        break;
    case 0x35:
        gc->setColor(GraphicsContext::BLUE);
        color = GraphicsContext::BLUE;
        break;
    case 0x36:
        gc->setColor(GraphicsContext::GREEN);
        color = GraphicsContext::GREEN;
        break;
    case 0x6C: // L key
        mode = 0;
        break;
    case 0x74: // T key
        mode = 1;
        break;
    case 0xFF08: // Backspace key
        undoShape(gc);
        break;
    }
}