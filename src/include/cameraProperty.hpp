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

    double speed;

    bool firsttap;
    int sx, sy;

public:
    void update();
    void draw() {}

    void set(double x, double y);

    camera(PropertyControlSystem *pcs);
    ~camera();
};
