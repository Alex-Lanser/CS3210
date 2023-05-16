#include <iostream>
#include <cmath>
#include "viewcontext.h"
#include "matrix.h"
using namespace std;

// Constructor
ViewContext::ViewContext(int width, int height)
{
    this->width = width;
    this->height = height;
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

    // Translate to origin
    originTranslate[0][3] = width / -2;
    originTranslate[1][3] = height / -2;
    inverseOriginTranslate[0][3] = width / 2;
    inverseOriginTranslate[1][3] = height / 2;

    // Translate to center of screen
    centerTranslate[0][3] = width / 2;
    centerTranslate[1][3] = height / 2;
    inverseCenterTranslate[0][3] = width / -2;
    inverseCenterTranslate[1][3] = height / -2;

    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    transform[1][1] = cos(90 * M_PI / 180);
    transform[1][2] = -sin(90 * M_PI / 180);
    transform[2][1] = sin(90 * M_PI / 180);
    transform[2][2] = cos(90 * M_PI / 180);
    inverseTransform[1][1] = cos(-90 * M_PI / 180);
    inverseTransform[1][2] = -sin(-90 * M_PI / 180);
    inverseTransform[2][1] = sin(-90 * M_PI / 180);
    inverseTransform[2][2] = cos(-90 * M_PI / 180);
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
    translateOrigin();
    Matrix inverseTransform1 = Matrix::identity(4);
    Matrix transform1 = Matrix::identity(4);
    transform1[0][0] = cos(-45 * M_PI / 180);
    transform1[0][2] = sin(-45 * M_PI / 180);
    transform1[2][0] = -sin(-45 * M_PI / 180);
    transform1[2][2] = cos(-45 * M_PI / 180);
    inverseTransform1[0][0] = cos(45 * M_PI / 180);
    inverseTransform1[0][2] = sin(45 * M_PI / 180);
    inverseTransform1[2][0] = -sin(45 * M_PI / 180);
    inverseTransform1[2][2] = cos(45 * M_PI / 180);
    modelToDevice = transform1 * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform1;
    translateCenter();
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

// Translate up by 10px
void ViewContext::translateUp()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[1][3] = 10;
    transform[1][3] = -10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate right by 10px
void ViewContext::translateRight()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[0][3] = -10;
    transform[0][3] = 10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate down by 10px
void ViewContext::translateDown()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[1][3] = -10;
    transform[1][3] = 10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate left by 10px
void ViewContext::translateLeft()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[0][3] = 10;
    transform[0][3] = -10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate out (towards) 10px
void ViewContext::translateOut()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[2][3] = 10;
    transform[2][3] = -10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate in (away) 10px
void ViewContext::translateIn()
{
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[2][3] = -10;
    transform[2][3] = 10;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
}

// Translate to the origin
void ViewContext::translateOrigin()
{
    modelToDevice = originTranslate * modelToDevice;
    deviceToModel = deviceToModel * inverseOriginTranslate;
}

// Translate to the center of the screen
void ViewContext::translateCenter()
{
    modelToDevice = centerTranslate * modelToDevice;
    deviceToModel = deviceToModel * inverseCenterTranslate;
}
// Scale the image up by 2
void ViewContext::scaleUp()
{
    // Translate to the origin
    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[0][0] = 1 / 2;
    inverseTransform[1][1] = 1 / 2;
    inverseTransform[2][2] = 1 / 2;
    transform[0][0] = 2;
    transform[1][1] = 2;
    transform[2][2] = 2;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
}

void ViewContext::scaleDown()
{
    // Translate to the origin
    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    inverseTransform[0][0] = 1 / 0.5;
    inverseTransform[1][1] = 1 / 0.5;
    inverseTransform[2][2] = 1 / 0.5;
    transform[0][0] = 0.5;
    transform[1][1] = 0.5;
    transform[2][2] = 0.5;
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
}

void ViewContext::rotateXClockwise()
{
    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    transform[1][1] = cos(-10 * M_PI / 180);
    transform[1][2] = -sin(-10 * M_PI / 180);
    transform[2][1] = sin(-10 * M_PI / 180);
    transform[2][2] = cos(-10 * M_PI / 180);
    inverseTransform[1][1] = cos(10 * M_PI / 180);
    inverseTransform[1][2] = -sin(10 * M_PI / 180);
    inverseTransform[2][1] = sin(10 * M_PI / 180);
    inverseTransform[2][2] = cos(10 * M_PI / 180);
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
}

void ViewContext::rotateXCounterclockwise()
{
    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    transform[1][1] = cos(10 * M_PI / 180);
    transform[1][2] = -sin(10 * M_PI / 180);
    transform[2][1] = sin(10 * M_PI / 180);
    transform[2][2] = cos(10 * M_PI / 180);
    inverseTransform[1][1] = cos(-10 * M_PI / 180);
    inverseTransform[1][2] = -sin(-10 * M_PI / 180);
    inverseTransform[2][1] = sin(-10 * M_PI / 180);
    inverseTransform[2][2] = cos(-10 * M_PI / 180);
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
}
void ViewContext::rotateYClockwise()
{
    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    transform[0][0] = cos(-10 * M_PI / 180);
    transform[0][2] = sin(-10 * M_PI / 180);
    transform[2][0] = -sin(-10 * M_PI / 180);
    transform[2][2] = cos(-10 * M_PI / 180);
    inverseTransform[0][0] = cos(10 * M_PI / 180);
    inverseTransform[0][2] = sin(10 * M_PI / 180);
    inverseTransform[2][0] = -sin(10 * M_PI / 180);
    inverseTransform[2][2] = cos(10 * M_PI / 180);
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
}
void ViewContext::rotateYCounterclockwise()
{
    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    transform[0][0] = cos(10 * M_PI / 180);
    transform[0][2] = sin(10 * M_PI / 180);
    transform[2][0] = -sin(10 * M_PI / 180);
    transform[2][2] = cos(10 * M_PI / 180);
    inverseTransform[0][0] = cos(-10 * M_PI / 180);
    inverseTransform[0][2] = sin(-10 * M_PI / 180);
    inverseTransform[2][0] = -sin(-10 * M_PI / 180);
    inverseTransform[2][2] = cos(-10 * M_PI / 180);
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
}
void ViewContext::undoAll()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            modelToDevice[i][j] = 0;
            deviceToModel[i][j] = 0;
        }
    }
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

    // Translate to origin
    originTranslate[0][3] = width / -2;
    originTranslate[1][3] = height / -2;
    inverseOriginTranslate[0][3] = width / 2;
    inverseOriginTranslate[1][3] = height / 2;

    // Translate to center of screen
    centerTranslate[0][3] = width / 2;
    centerTranslate[1][3] = height / 2;
    inverseCenterTranslate[0][3] = width / -2;
    inverseCenterTranslate[1][3] = height / -2;

    translateOrigin();
    Matrix inverseTransform = Matrix::identity(4);
    Matrix transform = Matrix::identity(4);
    transform[1][1] = cos(90 * M_PI / 180);
    transform[1][2] = -sin(90 * M_PI / 180);
    transform[2][1] = sin(90 * M_PI / 180);
    transform[2][2] = cos(90 * M_PI / 180);
    inverseTransform[1][1] = cos(-90 * M_PI / 180);
    inverseTransform[1][2] = -sin(-90 * M_PI / 180);
    inverseTransform[2][1] = sin(-90 * M_PI / 180);
    inverseTransform[2][2] = cos(-90 * M_PI / 180);
    modelToDevice = transform * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform;
    translateCenter();
    translateOrigin();
    Matrix inverseTransform1 = Matrix::identity(4);
    Matrix transform1 = Matrix::identity(4);
    transform1[0][0] = cos(-45 * M_PI / 180);
    transform1[0][2] = sin(-45 * M_PI / 180);
    transform1[2][0] = -sin(-45 * M_PI / 180);
    transform1[2][2] = cos(-45 * M_PI / 180);
    inverseTransform1[0][0] = cos(45 * M_PI / 180);
    inverseTransform1[0][2] = sin(45 * M_PI / 180);
    inverseTransform1[2][0] = -sin(45 * M_PI / 180);
    inverseTransform1[2][2] = cos(45 * M_PI / 180);
    modelToDevice = transform1 * modelToDevice;
    deviceToModel = deviceToModel * inverseTransform1;
    translateCenter();
}