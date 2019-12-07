#include "include/positionProperty.hpp"
#include "include/pcs.hpp"

#include <iostream>

double positionProperty::gx = 0;
double positionProperty::gy = 0;

positionProperty::positionProperty(PropertyControlSystem *pcs) : x(0), y(0), property(PROPERTY_POSITION)
{
    useglobalxy = true;
    std::cout << "[?] New position property added" << std::endl;
}

void positionProperty::draw() {}

positionProperty::~positionProperty()
{
}

void positionProperty::update()
{
    if (useglobalxy)
    {
        x = gx + x;
        y = gy + y;
    }
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
    return x;
}

double positionProperty::getY()
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