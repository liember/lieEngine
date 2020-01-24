#include "includer.hpp"

wather::wather(/* args */)
{
    pos = new positionProperty(this);
    connectProperty(pos);
    cam = new camera(this);
    cam->set(0, 0);
    connectProperty(cam);
}

wather::wather(int x, int y)
{
    pos = new positionProperty(this);
    connectProperty(pos);
    cam = new camera(this);
    cam->set(-x, -y);
    connectProperty(cam);
}

wather::~wather()
{
}

double wather::getPosX()
{
    return pos->getGX();
}

double wather::getPosY()
{
    return pos->getGY();
}

void wather::setPos(double x, double y)
{
    pos->setGlobal(x, y);
}

void wather::setPosY(double v)
{
    cam->setX(v);
}

void wather::setPosX(double v)
{
    cam->setX(v);
}
