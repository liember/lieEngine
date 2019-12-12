
#include "include/property.hpp"
#include "include/speedProperty.hpp"
#include "include/WASDControllerProperty.hpp"
#include "include/pcs.hpp"
#include "include/WASDAnimatorProperty.hpp"
#include "include/positionLimitProperty.hpp"

#include <iostream>

WASDAnimatorProperty::WASDAnimatorProperty(PropertyControlSystem *pcs) : property(PROPERY_WASD_ANIMATOR)
{
    speed = 0.1;
    inertion = true;
    vel = static_cast<speedProperty *>(pcs->getProperty(PROPERTY_SPEED));
    controller = static_cast<WASDControllerProperty *>(pcs->getProperty(PROPERTY_WASD_CONTROLLER));
    pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
}

WASDAnimatorProperty::~WASDAnimatorProperty()
{
}

void WASDAnimatorProperty::setInertion(bool val)
{
    inertion = val;
}

void WASDAnimatorProperty::setSpeed(double val)
{
    speed = val;
}

void WASDAnimatorProperty::update()
{

    if (controller->getStates()[SPACE_KEY])
    {
        moveVertical(-200);
    }

    if (controller->getStates()[W_KEY])
    {
        moveVertical(-speed);
    }
    else
    {
        moveVertical(0);
    }
    if (controller->getStates()[A_KEY])
    {
        moveHorizontal(-speed);
    }
    else
    {
        moveHorizontal(0);
    }
    if (controller->getStates()[S_KEY])
    {
        moveVertical(speed);
    }
    else
    {
        moveVertical(0);
    }
    if (controller->getStates()[D_KEY])
    {
        moveHorizontal(speed);
    }
    else
    {
        moveHorizontal(0);
    }
}

void WASDAnimatorProperty::moveVertical(double val)
{
    if (inertion)
    {
        vel->set(vel->getX(), vel->getY() + val);
    }
    else
    {
        vel->set(vel->getX(), val);
    }
}

void WASDAnimatorProperty::moveHorizontal(double val)
{
    if (inertion)
    {
        vel->set(vel->getX() + val, vel->getY());
    }
    else
    {
        vel->set(val, vel->getY());
    }
}