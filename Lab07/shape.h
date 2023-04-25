#ifndef shape_h
#define shape_h

#include <iostream>
#include "x11context.h"
#include "gcontext.h"
#include "viewcontext.h"
using namespace std;

class Shape
{
public:
    virtual ~Shape(){};
    virtual void draw(GraphicsContext *, ViewContext *) = 0;
    virtual Shape *clone() = 0;

protected:
    unsigned int color;
};

#endif
