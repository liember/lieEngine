#pragma once

#include "property.hpp"
#include "pcs.hpp"
#include "speedProperty.hpp"

class gravityProperty : public property
{
private:
    double Ygravity, Xgravity;
    speedProperty *speed;

public:
    void setY(double x, double y);

    void draw();
    void update();

    gravityProperty(PropertyControlSystem *pcs);
    ~gravityProperty();
};
