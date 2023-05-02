#include <iostream>
#include "viewcontext.h"
#include "matrix.h"
using namespace std;

// Constructor
ViewContext::ViewContext(int width, int height)
{
    modelToDevice[0][0] = 1;
    modelToDevice[0][3] = width / 2;
    modelToDevice[1][1] = -1;
    modelToDevice[1][3] = height / 2;
    modelToDevice[2][2] = 1;
    modelToDevice[3][3] = 1;

    deviceToModel[0][0] = 1;
    deviceToModel[0][3] = width / -2;
    deviceToModel[1][1] = -1;
    deviceToModel[1][3] = height / 2;
    deviceToModel[2][2] = 1;
    deviceToModel[3][3] = 1;
}

// Model To Device
Matrix ViewContext::ModelToDevice(Matrix point)
{
    return modelToDevice * point;
}

// Device to model
Matrix ViewContext::DeviceToModel(Matrix point)
{
    return deviceToModel * point;
}

// Translate up by 5px
void ViewContext::translateUp()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[1][3] = 10;
    transform[1][3] = -10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate right by 5px
void ViewContext::translateRight()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[0][3] = -10;
    transform[0][3] = 10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate down by 5px
void ViewContext::translateDown()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[1][3] = -10;
    transform[1][3] = 10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate left by 5px
void ViewContext::translateLeft()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[0][3] = 10;
    transform[0][3] = -10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}