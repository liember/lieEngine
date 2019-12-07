#pragma once

#include "property.hpp"
#include "pcs.hpp"

class positionProperty : public property
{
private:
    double x;
    double y;

    bool useglobalxy;

    static double gx;
    static double gy;

public:
    void update();
    void draw();

    void enableGlobal(bool v);

    static void setGlobal(double ix, double iy);
    static double getGX();
    static double getGY();

    double getX();
    double getY();

    void setX(double dx);
    void setY(double dy);

    positionProperty(PropertyControlSystem *pcs);
    ~positionProperty();
};
