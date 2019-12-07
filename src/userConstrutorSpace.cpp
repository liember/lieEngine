#include <iostream>

#include "include/objectsManager.hpp"
#include "include/game.hpp"
#include "include/timer.hpp"
#include "include/gameobj.hpp"
#include "include/property.hpp"

#include "include/positionProperty.hpp"
#include "include/positionLimitProperty.hpp"
#include "include/speedProperty.hpp"
#include "include/textureProperty.hpp"
#include "include/WASDAnimatorProperty.hpp"
#include "include/WASDControllerProperty.hpp"
#include "include/tilemapProperty.hpp"
#include "include/textureProperty.hpp"

#include "include/cameraProperty.hpp"

void game::initGame()
{
    gameobj *obj = new gameobj();
    positionProperty *p = new positionProperty(obj);
    p->setX(100);
    p->setY(100);
    obj->connectProperty(p);
    obj->addProperty(PROPERTY_SPEED);
    textureProperty *t = new textureProperty(obj);
    t->setTexture("assets/b2.png");
    obj->connectProperty(t);
    gmsManager.add(obj);

    obj = new gameobj();
    p = new positionProperty(obj);
    p->setX(10);
    p->setY(10);
    obj->connectProperty(p);
    obj->addProperty(PROPERTY_SPEED);
    t = new textureProperty(obj);
    t->setTexture("assets/b2.png");
    obj->connectProperty(t);
    gmsManager.add(obj);

    obj = new gameobj();
    obj->addProperty(PROPERTY_TILEMAP);
    gmsManager.add(obj);

    obj = new gameobj();
    obj->addProperty(PROPERTY_CAMERA);
    gmsManager.add(obj);
}

void game::updateGame()
{
}