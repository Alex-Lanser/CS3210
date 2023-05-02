#include "mydrawing.h"
#include "gcontext.h"
#include "viewcontext.h"
#include "matrix.h"
using namespace std;

// Constructor
MyDrawing::MyDrawing(int width, int height)
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
    cout << endl;
    cout << "To translate the image, use the arrow keys respectively." << endl;
    cout << "To rotate: Q-Counter Clockwise; E-Clockwise." << endl;
    cout << "To scale: W-Scale up; S-Scale down." << endl;
    numClicks = 0;                  // Track the number of clicks
    mode = 0;                       // Default mode is line
    color = GraphicsContext::GREEN; // Default color is green
    vc = new ViewContext(width, height);
}
// Destructor
MyDrawing::~MyDrawing()
{
    delete vc;
}
void MyDrawing::paint(GraphicsContext *gc)
{
    im.draw(gc, vc);
}
void MyDrawing::mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y)
{
    if (mode == 0) // Line
    {
        if (numClicks == 0) // 1st click
        {
            x0 = x;
            y0 = y;
            numClicks++;
        }
        else // 2nd click. Draw line
        {
            gc->drawLine(x0, y0, x, y);
            coord0[0][0] = x0;
            coord0[1][0] = y0;
            coord0[3][0] = 1;
            coord1[0][0] = x;
            coord1[1][0] = y;
            coord1[3][0] = 1;
            Matrix point0 = vc->DeviceToModel(coord0);
            Matrix point1 = vc->DeviceToModel(coord1);
            im.addLine(point0[0][0], point0[1][0], point1[0][0], point1[1][0], color);
            numClicks = 0;
        }
    }
    else if (mode == 1) // Triangle
    {
        if (numClicks == 0) // 1st click
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
        else // 3rd click. Draw triangle
        {
            gc->drawLine(x0, y0, x1, y1);
            gc->drawLine(x0, y0, x, y);
            gc->drawLine(x1, y1, x, y);
            coord0[0][0] = x0;
            coord0[1][0] = y0;
            coord0[3][0] = 1;
            coord1[0][0] = x1;
            coord1[1][0] = y1;
            coord1[3][0] = 1;
            coord2[0][0] = x;
            coord2[1][0] = y;
            coord2[3][0] = 1;
            Matrix point0 = vc->DeviceToModel(coord0);
            Matrix point1 = vc->DeviceToModel(coord1);
            Matrix point2 = vc->DeviceToModel(coord2);
            im.addTriangle(point0[0][0], point0[1][0], point1[0][0], point1[1][0], point2[0][0], point2[1][0], color);
            numClicks = 0;
        }
    }
}
void MyDrawing::undoShape(GraphicsContext *gc)
{
    gc->clear();
    im = im.undoShape(im);
    paint(gc);
}
void MyDrawing::rotateClockwise(GraphicsContext *gc)
{
    gc->clear();
    paint(gc);
}
void MyDrawing::rotateCounterclockwise(GraphicsContext *gc)
{
    gc->clear();
    paint(gc);
}
void MyDrawing::scaleUp(GraphicsContext *gc)
{
    gc->clear();
    paint(gc);
}
void MyDrawing::scaleDown(GraphicsContext *gc)
{
    gc->clear();
    paint(gc);
}
void MyDrawing::translateUp(GraphicsContext *gc)
{
    gc->clear();
    vc->translateUp();
    paint(gc);
}
void MyDrawing::translateRight(GraphicsContext *gc)
{
    vc->translateRight();
    gc->clear();
    paint(gc);
}
void MyDrawing::translateDown(GraphicsContext *gc)
{
    vc->translateDown();
    gc->clear();
    paint(gc);
}
void MyDrawing::translateLeft(GraphicsContext *gc)
{
    vc->translateLeft();
    gc->clear();
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
    case 0x6C:    // L key
        mode = 0; // Line mode
        break;
    case 0x74:    // T key
        mode = 1; // Triangle mode
        break;
    case 0xFF08: // Backspace key
        undoShape(gc);
        break;
    case 0x65: // E (Rotate clockwise)
        rotateClockwise(gc);
        break;
    case 0x71: // Q (Rotate counter clockwise)
        rotateCounterclockwise(gc);
        break;
    case 0x77: // W Scale up
        scaleUp(gc);
        break;
    case 0x73: // S Scale down
        scaleDown(gc);
        break;
    case 0xFF52: // Up arrow translate up
        translateUp(gc);
        break;
    case 0xFF53: // Right arrow translate right
        translateRight(gc);
        break;
    case 0xFF54: // Down arrow translate down
        translateDown(gc);
        break;
    case 0xFF51: // Left arrow translate left
        translateLeft(gc);
        break;
    }
}