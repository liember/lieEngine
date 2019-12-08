#include "includer.hpp"
#include <math.h>

//if you need this
gameobj *obj;
positionProperty *pos;
speedProperty *vel;
textureProperty *tex;
positionLimitProperty *lim;

//planets
planet *pl[3];

void game::initGame()
{
    obj = new gameobj();
    obj->addProperty(PROPERTY_TILEMAP);
    gmsManager.add(obj);

    pl[1] = new planet();
    pl[1]->setPos(10, 200);
    pl[1]->setVel(202, 112);
    gmsManager.add(pl[1]);

    pl[2] = new planet();
    pl[2]->setPos(200, 10);
    gmsManager.add(pl[2]);

    obj = new gameobj();
    obj->addProperty(PROPERTY_CAMERA);
    gmsManager.add(obj);
}

//world gravitation
void game::updateGame()
{
    double x1 = pl[1]->getPosX();
    double y1 = pl[1]->getPosY();

    double x2 = pl[2]->getPosX();
    double y2 = pl[2]->getPosY();

    double hypotenuse = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (hypotenuse == 0)
    {
        throw new zeroRadius();
    }

    double gravity = 0.00001;

    double potence = gravity * (pl[1]->getMass() * pl[2]->getMass()) / pow(hypotenuse, 2);

    double xVel = -(x1 - x2) / hypotenuse * potence;
    double yVel = -(y1 - y2) / hypotenuse * potence;
    pl[1]->addVel(xVel, yVel);
    std::cout << xVel << " " << yVel << std::endl;
}
