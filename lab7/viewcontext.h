#ifndef viewcontext_h
#define viewcontext_h

#include <iostream>
#include "matrix.h"
using namespace std;

class ViewContext
{
public:
    ViewContext(int width, int height);
    Matrix ModelToDevice(Matrix point);
    Matrix DeviceToModel(Matrix point);
    void translateUp();
    void translateRight();
    void translateDown();
    void translateLeft();
    void scaleUp();
    void scaleDown();
    void rotateCounterclockwise();
    void rotateClockwise();

private:
    Matrix modelToDevice = Matrix(4, 4);
    Matrix deviceToModel = Matrix(4, 4);
    Matrix originTranslate = Matrix::identity(4);
    Matrix centerTranslate = Matrix::identity(4);
    Matrix inverseOriginTranslate = Matrix::identity(4);
    Matrix inverseCenterTranslate = Matrix::identity(4);
    void translateOrigin();
    void translateCenter();
};
#endif