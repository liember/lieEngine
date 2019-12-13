#include "include/positionProperty.hpp"
#include "include/pcs.hpp"

#include <iostream>

double positionProperty::gx = 0;
double positionProperty::gy = 0;

positionProperty::positionProperty(PropertyControlSystem *pcs) : property(PROPERTY_POSITION)
{
    x = 0;
    y = 0;
    useglobalxy = true;
}

void positionProperty::setGUsing(bool b)
{
    useglobalxy = b;
}

void positionProperty::draw() {}

positionProperty::~positionProperty()
{
}

void positionProperty::update()
{
}

void positionProperty::setGlobal(double ix, double iy)
{
    gx = ix;
    gy = iy;
}

void positionProperty::enableGlobal(bool v)
{
    useglobalxy = v;
}

double positionProperty::getGX()
{
    return gx;
}

double positionProperty::getGY()
{
    return gy;
}

double positionProperty::getX()
{
    if (useglobalxy)
    {
        return x + gx;
    }

    return x;
}

double positionProperty::getY()
{
    if (useglobalxy)
    {
        return y + gy;
    }
    return y;
}

double positionProperty::getOnlyX()
{
    return x;
}

double positionProperty::getOnlyY()
{
    return y;
}

void positionProperty::setX(double dx)
{
    x = dx;
}

void positionProperty::setY(double dy)
{
    y = dy;
}