#include "includer.hpp"

//if you need this
gameobj *obj;
positionProperty *pos;
speedProperty *vel;
textureProperty *tex;
positionLimitProperty *lim;

//planets
planet *pl[10];

double gravity = 0.00001;

void game::initGame()
{
    playerShip *pla = new playerShip();
    pla->setPos(900, 250);
    pla->setTex("assets/bird.png");
    pla->setVel(0, 200);
    pla->setMass(9);
    pla->setSize(100);
    gmsManager.add(pla);

    obj = new gameobj();
    obj->addProperty(PROPERTY_TILEMAP);
    gmsManager.add(obj);

    pl[0] = new planet();
    pl[0]->setPos(400, 250);
    pl[0]->setVel(-400, 0);
    pl[0]->setMass(99);
    pl[0]->setSize(100);
    gmsManager.add(pl[0]);

    pl[1] = new planet(); //sun
    pl[1]->setTex("assets/sun.png");
    pl[1]->setPos(400, 0);
    pl[1]->setVel(0, 0);
    pl[1]->setMass(9999999999.0);
    pl[1]->setSize(110);
    gmsManager.add(pl[1]);

    pl[2] = new planet();
    pl[2]->setPos(400, 510);
    pl[2]->setVel(-320, 0);
    pl[2]->setMass(9.0);
    pl[2]->setSize(90);
    gmsManager.add(pl[2]);

    pl[3] = pla;

    obj = new gameobj();
    obj->addProperty(PROPERTY_CAMERA);
    gmsManager.add(obj);
}

//world gravitation
void game::updateGame()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
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

void game::specificRenderBefore()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                double x1 = pl[j]->getGlobX();
                x1 += pl[j]->getSize() / 2;
                double y1 = pl[j]->getGlobY();
                y1 += pl[j]->getSize() / 2;

                double x2 = pl[i]->getGlobX();
                x2 += pl[i]->getSize() / 2;
                double y2 = pl[i]->getGlobY();
                y2 += pl[i]->getSize() / 2;

                SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 0);
                SDL_RenderDrawLine(getRenderer(), x1, y1, x2, y2);
            }
        }
    }
}

void game::specificRenderAfter()
{
}