#include "include/speedProperty.hpp"
#include "include/pcs.hpp"
#include "include/timer.hpp"

#include <iostream>

void speedProperty::update()
{
    position->setX(position->getOnlyX() + x * timer::GetDelta());
    position->setY(position->getOnlyY() + y * timer::GetDelta());
}

void speedProperty::draw() {}

speedProperty::speedProperty(PropertyControlSystem *pcs) : property(PROPERTY_SPEED)
{
    x = 0;
    y = 0;
    std::cout << "[?] New speed property added" << std::endl;
    position = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
}

speedProperty::~speedProperty()
{
}

void speedProperty::set(double dx, double dy)
{
    x = dx;
    y = dy;
}

double speedProperty::getX()
{
    return x;
}

double speedProperty::getY()
{
    return y;
}