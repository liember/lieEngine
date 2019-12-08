#pragma once

#include "../includer.hpp"

class planet : public gameobj
{
private:
    positionProperty *pos;
    speedProperty *vel;
    textureProperty *tex;

    double mass;

public:
    void setPos(double x, double y);
    void setVel(double x, double y);
    void addVel(double x, double y);

    double getPosX();
    double getPosY();

    double getMass();

    planet(/* args */);
    ~planet();
};