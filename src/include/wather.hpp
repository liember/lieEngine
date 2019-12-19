#pragma once

#include "../includer.hpp"

class wather : public gameobj
{
private:
    positionProperty *pos;
    camera *cam;

public:
    double getPosX();
    double getPosY();

    void setPosX(double v);
    void setPosY(double v);
    void setPos(double x, double y);

    wather(/* args */);
    wather(int x, int y);
    ~wather();
};