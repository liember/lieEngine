#pragma once

#include "../includer.hpp"

class planet : public gameobj
{
private:
    positionProperty *pos;
    speedProperty *vel;
    textureProperty *tex;
    colliderProperty *col;

    double mass;
    int size;

    bool gravity;

public:
    void setPos(double x, double y);
    void setVel(double x, double y);
    void addVel(double x, double y);

    void setMass(double val);
    double getMass();

    bool isGravit();

    void setSize(int s);

    double getPosX();
    double getPosY();

    void collide();

    void updateCollisions();

    planet(/* args */);
    ~planet();
};