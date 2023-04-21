#include "matrix.h"
#include "x11context.h"
#include <unistd.h>
using namespace std;
// Varnell 2023
// incomplete
// Demonstrates barycentric gradient fill algorithm
// Color class stores red, green and blue color components
class Color
{
public:
    Color(unsigned int color)
    {
        unsigned int red_mask = 0xFF0000;
        unsigned int green_mask = 0x00FF00;
        unsigned int blue_mask = 0x0000FF;
        red = (color & red_mask) >> 16;
        green = (color & green_mask) >> 8;
        blue = (color & blue_mask) >> 0;
    }
    unsigned int red;
    unsigned int green;
    unsigned int blue;
};
// helper function returns area of a triangle (x2) given three points
int area(Matrix A, Matrix B, Matrix C)
{
    return A[0][0] * (B[1][0] - C[1][0]) +
           B[0][0] * (C[1][0] - A[1][0]) +
           C[0][0] * (A[1][0] - B[1][0]);
}
int main()
{
    /*** THREE TRIANGLE VERTEX POINTS ***/
    Matrix A(2, 1);
    Matrix B(2, 1);
    Matrix C(2, 1);
    /*** SET X AND Y COORDINATES OF THREE VERTICES ***/
    A[0][0] = 200;
    A[1][0] = 500;
    B[0][0] = 100;
    B[1][0] = 100;
    C[0][0] = 450;
    C[1][0] = 300;
    /*** SET COLOR OF THREE VERTICES ***/
    unsigned int Avertexcolor = 0x44CDDE;
    unsigned int Bvertexcolor = 0xE33C39;
    unsigned int Cvertexcolor = 0xFEEA4B;
    // create a color class for each vertex
    Color Acol(Avertexcolor);
    Color Bcol(Bvertexcolor);
    Color Ccol(Cvertexcolor);
    /*** SET WINDOW WIDTH AND HEIGHT ***/
    int width = 800;
    int height = 600;
    GraphicsContext *gc = new X11Context(width, height, GraphicsContext::WHITE);
    // current pixel:
    Matrix point(2, 2);
    // area of entire triangle
    double areaTriangle = area(A, B, C);
    // 3 barycentric coordinates:
    double u;
    double v;
    double w;
    // individual colors of current pixel
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    // color of current pixel
    unsigned int color;
    /**** ITERATE OVER EVERY (X,Y) PIXEL IN THE WINDOW ***/
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            point[0][0] = x;
            point[1][0] = y;
            /*** FIND 3 BARYCENTRIC COORDINATES ***/
            u = area(B, C, point) / areaTriangle;
            v = area(C, A, point) / areaTriangle;
            w = area(A, B, point) / areaTriangle;
            /*** IF ALL 3 COORDINATES ARE >= 0, PIXEL IS IN TRIANGLE ***/
            if (u >= 0 && v >= 0 && w >= 0)
            {
                /*** THE GREEN RED AND BLUE COLOR COMPONENTS ARE THE 3
                 * VERTEX COLORS WEIGHTED BY THE BARYCENTRIC COORDINATES ***/
                red = u * Acol.red + v * Bcol.red + w * Ccol.red;
                green = u * Acol.green + v * Bcol.green + w * Ccol.green;
                blue = u * Acol.blue + v * Bcol.blue + w * Ccol.blue;
                color = (red << 16) + (green << 8) + blue;
                gc->setColor(color);
                gc->setPixel(x, y);
            }
        }
    }
    sleep(5);
    delete gc;
    return 0;
}