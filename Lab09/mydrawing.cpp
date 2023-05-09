#include "mydrawing.h"
#include "gcontext.h"
#include "viewcontext.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstring>
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
    cout << "To return back to normal: Enter Key." << endl;
    cout << "To insert an image from stl file: Z" << endl;
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
    vc->rotateClockwise();
    gc->clear();
    paint(gc);
}
void MyDrawing::rotateCounterclockwise(GraphicsContext *gc)
{
    vc->rotateCounterclockwise();
    gc->clear();
    paint(gc);
}
void MyDrawing::scaleUp(GraphicsContext *gc)
{
    vc->scaleUp();
    gc->clear();
    paint(gc);
}
void MyDrawing::scaleDown(GraphicsContext *gc)
{
    vc->scaleDown();
    gc->clear();
    paint(gc);
}
void MyDrawing::translateUp(GraphicsContext *gc)
{
    vc->translateUp();
    gc->clear();
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
void MyDrawing::undoAll(GraphicsContext *gc, ViewContext *vc)
{
    vc->undoAll();
    gc->clear();
    paint(gc);
}
void MyDrawing::readFromFile(string filename)
{
    ifstream ifile(filename);
    // Empty string to store line from stl file
    string line;
    // Variables to store x,y,z file data in
    double x0;
    double y0;
    double z0;
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    string type;
    int count = 0;
    // Read lines of the stl file until the last one is reached
    while (!ifile.eof())
    {
        // Store next line of file
        getline(ifile, line);
        // Create input string stream connected to line string
        istringstream iss(line);
        // Extract data from file
        iss >> type;
        int vertexR = type.compare("vertex");
        if (vertexR == 0 && count == 0)
        {
            iss >> x0;
            iss >> y0;
            iss >> z0;
            count++;
        }
        else if (vertexR == 0 && count == 1)
        {
            iss >> x1;
            iss >> y1;
            iss >> z1;
            count++;
        }
        else if (vertexR == 0 && count == 2)
        {
            iss >> x2;
            iss >> y2;
            iss >> z1;
            count = 0;
            im.addTriangle(x0, y0, x1, y1, x2, y2, color);
        }
    }
}
void MyDrawing::keyDown(GraphicsContext *gc, unsigned int keycode)
{
    // cout << keycode << endl;
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
    case 0x75: // Return back to normal, U key
        undoAll(gc, vc);
        break;
    case 0x7A: // Insert stl file, Z key
        cout << "Enter file name: " << endl;
        string fileinput;
        cin >> fileinput;
        gc->clear();
        im.erase();
        readFromFile(fileinput);
        paint(gc);
        break;
    }
}