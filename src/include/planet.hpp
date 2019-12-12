#pragma once

#include "../includer.hpp"

class planet : public gameobj
{
private:
    positionProperty *pos;
    speedProperty *vel;
    textureProperty *tex;
    colliderProperty *col;
    textProperty *text;

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
    int getSize() { return size; }

    double getPosX();
    double getPosY();

    double getGlobX();
    double getGlobY();

    void collide();
    void setTex(const char *p);

    planet(/* args */);
    ~planet();
};