#pragma once

#include "positionLimitProperty.hpp"
#include "property.hpp"
#include "mouse.hpp"

class camera : public property
{
private:
    positionLimitProperty *lim;
    positionProperty *pos;
    mouse *m;

    int speed;

public:
    void update();
    void draw() {}

    camera(PropertyControlSystem *pcs);
    ~camera();
};

camera::camera(PropertyControlSystem *pcs)
{
    setID(PROPERTY_CAMERA);
    lim = static_cast<positionLimitProperty *>(pcs->getProperty(PROPERTY_POSITION_LIMIT));
    pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
    pos->enableGlobal(false);
    m = static_cast<mouse *>(pcs->getProperty(PROPERTY_MOUSE));
}

camera::~camera()
{
}

void camera::update()
{
    if (lim->checkRight(m->getx()))
    {
        pos->setGlobal(pos->getGX() + speed, pos->getGY());
    }
    if (lim->checkLeft(m->getx()))
    {
        pos->setGlobal(pos->getGX() - speed, pos->getGY());
    }
    if (lim->checkBot(m->gety()))
    {
        pos->setGlobal(pos->getGX(), pos->getGY() + speed);
    }
    if (lim->checkTop(m->gety()))
    {
        pos->setGlobal(pos->getGX(), pos->getGY() - speed);
    }
}
