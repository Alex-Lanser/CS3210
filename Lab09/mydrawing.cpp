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
    cout << endl;
    cout << "To translate the image, use the arrow keys respectively." << endl;
    cout << "To traslate with the Z-axis, use T and G." << endl;
    cout << "To rotate Y-axis: Q-Counter Clockwise; E-Clockwise." << endl;
    cout << "To rotate X-axis: F-Counter Clockwise; R-Clockwise." << endl;
    cout << "To scale: W-Scale up; S-Scale down." << endl;
    cout << "To return back to normal: Enter Key." << endl;
    cout << "To insert an image from stl file: Z" << endl;
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
void MyDrawing::rotateXClockwise(GraphicsContext *gc)
{
    vc->rotateXClockwise();
    gc->clear();
    paint(gc);
}
void MyDrawing::rotateXCounterclockwise(GraphicsContext *gc)
{
    vc->rotateXCounterclockwise();
    gc->clear();
    paint(gc);
}
void MyDrawing::rotateYClockwise(GraphicsContext *gc)
{
    vc->rotateYClockwise();
    gc->clear();
    paint(gc);
}   
void MyDrawing::rotateYCounterclockwise(GraphicsContext *gc)
{
    vc->rotateYCounterclockwise();
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

void MyDrawing::translateOut(GraphicsContext *gc)
{
    vc->translateOut();
    gc->clear();
    paint(gc);
}
void MyDrawing::translateIn(GraphicsContext *gc)
{
    vc->translateIn();
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
            iss >> z2;
            count = 0;
            im.addTriangle(x0, y0, z0, x1, y1, z1, x2, y2, z2, color);
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
    case 0x65: // E (Rotate Y clockwise)
        rotateYCounterclockwise(gc);
        break;
    case 0x71: // Q (Rotate Y counter clockwise)
        rotateYClockwise(gc);
        break;
    case 0x72: // R (Rotate X clockwise)
        rotateXClockwise(gc);
        break;
    case 0x66: // F (Rotate X counter clockwise)
        rotateXCounterclockwise(gc);
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
    case 0x74: // T translate out
        translateOut(gc);
        break;
    case 0x67: // G translate in
        translateIn(gc);
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