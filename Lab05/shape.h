#ifndef shape_h
#define shape_h

#include <iostream>
#include "x11context.h"
#include "gcontext.h"
using namespace std;

class Shape
{
public:
    virtual ~Shape();
    virtual void draw(GraphicsContext *) = 0;
    virtual Shape *clone() = 0;

private:
    int color;
};

#endif
