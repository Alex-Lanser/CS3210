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

private:
    Matrix modelToDevice = Matrix(4, 4);
    Matrix deviceToModel = Matrix(4, 4);
};
#endif