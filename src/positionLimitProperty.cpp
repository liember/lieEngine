#include "include/property.hpp"
#include "include/positionProperty.hpp"
#include "include/gravityProperty.hpp"
#include "include/positionLimitProperty.hpp"

#include <iostream>

positionLimitProperty::positionLimitProperty(PropertyControlSystem *pcs) : property(PROPERTY_POSITION_LIMIT)
{
    std::cout << "[?] New position limit property added" << std::endl;
    pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
    vel = static_cast<speedProperty *>(pcs->getProperty(PROPERTY_SPEED));
    limYbot = new double(99999999999999999);
    limYtop = new double(-99999999999999999);
    limXleft = new double(-99999999999999999);
    limXriht = new double(99999999999999999);
}

positionLimitProperty::~positionLimitProperty()
{
    if (limYbot)
    {
        delete limYbot;
    }
    if (limYtop)
    {
        delete limYtop;
    }
    if (limXleft)
    {
        delete limXleft;
    }
    if (limXriht)
    {
        delete limXriht;
    }
}

void positionLimitProperty::update()
{
    if (limYbot && pos->getY() > *limYbot)
    {
        vel->set(vel->getX(), 0);
        pos->setY(*limYbot - 1);
    }
    if (limYtop && pos->getY() < *limYtop)
    {
        vel->set(vel->getX(), 0);
        pos->setY(*limYtop + 1);
    }
    if (limXleft && pos->getX() < *limXleft)
    {
        vel->set(0, vel->getY());
        pos->setX(*limXleft + 1);
    }
    if (limXriht && pos->getX() > *limXriht)
    {
        vel->set(0, vel->getY());
        pos->setX(*limXriht - 1);
    }
}

void positionLimitProperty::draw()
{
}

void positionLimitProperty::set(double **var, double s)
{
    if (var)
    {
        **var = s;
    }
    else
    {
        *var = new double(s);
    }
}

void positionLimitProperty::setBot(double s)
{
    set(&limYbot, s);
}

void positionLimitProperty::setTop(double s)
{
    set(&limYtop, s);
}

void positionLimitProperty::setLeft(double s)
{
    set(&limXleft, s);
}

void positionLimitProperty::setRight(double s)
{
    set(&limXriht, s);
}

double positionLimitProperty::getBot()
{
    return *limYbot;
}

double positionLimitProperty::getTop()
{
    return *limYtop;
}

double positionLimitProperty::getLeftWall()
{
    return *limXleft;
}

double positionLimitProperty::getRightWall()
{
    return *limXriht;
}

bool positionLimitProperty::nearBot()
{
    if (limYbot && *limYbot < pos->getY() + 0.1)
    {
        vel->set(vel->getX(), 0);
        pos->setY(pos->getY() - 1);
        return true;
    }
    return false;
}

bool positionLimitProperty::nearTop()
{
    if (limYtop && *limYtop < pos->getY() + 1)
    {
        return true;
    }
    return false;
}

bool positionLimitProperty::nearLeft()
{
    if (limXleft && *limXleft < pos->getX() + 1)
    {
        return true;
    }
    return false;
}

bool positionLimitProperty::nearRight()
{
    if (limXriht && *limXriht < pos->getX() + 1)
    {
        return true;
    }
    return false;
}

bool positionLimitProperty::checkBot(double p)
{
    if (limYbot && p > *limYbot)
    {
        return true;
    }
    return false;
}

bool positionLimitProperty::checkTop(double p)
{
    if (limYtop && p < *limYtop)
    {
        return true;
    }
    return false;
}

bool positionLimitProperty::checkLeft(double p)
{
    if (limXleft && p < *limXleft)
    {
        return true;
    }
    return false;
}

bool positionLimitProperty::checkRight(double p)
{
    if (limXriht && p > *limXriht)
    {
        return true;
    }
    return false;
}
