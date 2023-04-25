#include <iostream>
#include "viewcontext.h"
#include "matrix.h"
using namespace std;

// Constructor
ViewContext::ViewContext(int width, int height)
{
    modelToDevice[0][0] = 1;
    modelToDevice[0][1] = 0;
    modelToDevice[0][2] = width / 2;
    modelToDevice[0][3] = 0;
    modelToDevice[1][0] = 0;
    modelToDevice[1][1] = -1;
    modelToDevice[1][2] = height / 2;
    modelToDevice[1][3] = 0;
    modelToDevice[2][0] = 0;
    modelToDevice[2][1]= 0;
    modelToDevice[2][2] = 1;
    modelToDevice[2][3] = 0;
    for (int i = 0; i < 4; i++)
    {
        modelToDevice[3][i] = 0;
    }

    deviceToModel[0][0] = 1;
    deviceToModel[0][1] = 0;
    deviceToModel[0][2] = width / -2;
    deviceToModel[0][3] = 0;
    deviceToModel[1][0] = 0;
    deviceToModel[1][1] = -1; 
    deviceToModel[1][2] = height / 2;
    deviceToModel[1][3] = 0;
    deviceToModel[2][0] = 0;
    deviceToModel[2][1] = 0;
    deviceToModel[2][2] = 1;
    deviceToModel[2][3] = 0;
    for (int i = 0; i < 4; i++)
    {
        deviceToModel[3][i] = 0;
    }
}

Matrix ViewContext::ModelToDevice(Matrix point)
{
    return modelToDevice * point;
}
// Model to device