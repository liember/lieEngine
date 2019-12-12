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

    pl[0] = new planet();
    pl[0]->setPos(400, 300);
    pl[0]->setVel(-200, 140);
    pl[0]->setMass(99);
    pl[0]->setSize(100);
    gmsManager.add(pl[0]);

    pl[1] = new planet();
    pl[1]->setPos(100, 0);
    pl[1]->setVel(0, 0);
    pl[1]->setMass(9999999999.0);
    pl[1]->setSize(110);
    gmsManager.add(pl[1]);

    obj = new gameobj();
    obj->addProperty(PROPERTY_CAMERA);
    gmsManager.add(obj);
}

//world gravitation
void game::updateGame()
{
    double gravity = 0.00001;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i != j)
            {
                double x1 = pl[j]->getPosX();
                double y1 = pl[j]->getPosY();

                double x2 = pl[i]->getPosX();
                double y2 = pl[i]->getPosY();

                double hypotenuse = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

                double potence = gravity * (pl[i]->getMass()) / pow(hypotenuse, 2);

                double xVel = (-(x1 - x2) / hypotenuse * potence);
                double yVel = (-(y1 - y2) / hypotenuse * potence);
                if (pl[j]->isGravit())
                {
                    pl[j]->addVel(xVel, yVel);
                }
            }
        }
        pl[i]->collide();
    }
}
