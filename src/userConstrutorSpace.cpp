#include "includer.hpp"

// if you need this
gameobj *obj;
positionProperty *pos;
speedProperty *vel;
textureProperty *tex;
positionLimitProperty *lim;
textProperty *text;
buttonProperty *but;

camera *cam;

playerShip *pla;

// planets
planet *pl[10];

buttonProperty *quitB;
buttonProperty *darwLines;
bool draw = false;
buttonProperty *nextP;
int onP = 0;
buttonProperty *teleport;

double gravity = 0.0000667408;
int nearK = 70;

void game::initGame() {
  //############ menu ##############
  //############ quit
  obj = new gameobj();
  pos = new positionProperty(obj);
  pos->setX(30);
  pos->setY(580);
  obj->connectProperty(pos);

  text = new textProperty(obj);
  text->init("Quit");
  obj->connectProperty(text);

  quitB = new buttonProperty(obj);
  quitB->setSize(200, 60);
  obj->connectProperty(quitB);

  gmsManager.add(obj);

  //########### drawL
  obj = new gameobj();
  pos = new positionProperty(obj);
  pos->setX(260);
  pos->setY(580);
  obj->connectProperty(pos);

  text = new textProperty(obj);
  text->init("Draw lines");
  obj->connectProperty(text);

  darwLines = new buttonProperty(obj);
  darwLines->setSize(200, 60);
  obj->connectProperty(darwLines);

  gmsManager.add(obj);

  //########### nextPlanet
  obj = new gameobj();
  pos = new positionProperty(obj);
  pos->setX(490);
  pos->setY(580);
  obj->connectProperty(pos);

  text = new textProperty(obj);
  text->init("Next planet");
  obj->connectProperty(text);

  nextP = new buttonProperty(obj);
  nextP->setSize(200, 60);
  obj->connectProperty(nextP);

  gmsManager.add(obj);

  //########### teleport
  obj = new gameobj();
  pos = new positionProperty(obj);
  pos->setX(720);
  pos->setY(580);
  obj->connectProperty(pos);

  text = new textProperty(obj);
  text->init("Teleport player");
  obj->connectProperty(text);

  teleport = new buttonProperty(obj);
  teleport->setSize(200, 60);
  obj->connectProperty(teleport);

  gmsManager.add(obj);

  //############ player ##############

  pla = new playerShip();
  pla->setPos(0, 149 * nearK + 200);
  pla->setTex("assets/bird.png");
  pla->setVel(0 , -100);
  pla->setMass(0.00000001);
  pla->setSize(50);
  pla->setSpeed(0.01);
  gmsManager.add(pla);
  pl[8] = pla;

  //############ sun ##############
  // mass 1,989 e30
  // rad 695510
  pl[0] = new planet("sun", 695, 198900000, 0, 0, 0, 0, "assets/sun.png");
  gmsManager.add(pl[0]);

  //############ planets ##############
  
  // mnercury
  // mass 3,285 e23
  // rad 2439,7
  //Перигелий	46 001 009 км
  //speed 48
  pl[1] = new planet("mercury", 2 * 3, 3285, -48, 0, 0, 46 * nearK);
  gmsManager.add(pl[1]);

  // venus
  // mass 4,867 e24
  // rad 6051,7
  //~~108 000 000
  //speed 35
  pl[2] = new planet("venus", 6 * 3, 4867, -35, 0, 0, 108 * nearK);
  gmsManager.add(pl[2]);

  // earth
  // mass 5,972 e24
  // rad 6371
  // 149 600 000
  //speed 30
  pl[3] = new planet("earth", 6 * 3, 5972, -30, 0, 0, 149 * nearK);
  gmsManager.add(pl[3]);

  // mars
  // mass 6,39 e23
  // rad 3 389,5
  // 228 000 000
  //speed 24.13
  pl[4] = new planet("mars", 2 * 3, 639, -24.13, 0, 0, 228 * nearK);
  gmsManager.add(pl[4]);

  // jupiter
  // mass 1.898 e27
  // rad 69 911.5
  // 778,57 000 000
  //speed 24.13
  pl[5] = new planet("jupiter", 69 * 3, 18980000, -13, 0, 0, 778 * nearK );
  gmsManager.add(pl[5]);

  // uran
  // mass 8,6813⋅10 e25
  // rad 25 559 
  // 2,8 000 000 000
  //speed 6.81
  pl[6] = new planet("uran", 25 * 3, 8681300, -6.81, 0, 0, 2800 * nearK );
  gmsManager.add(pl[6]);

  // neptun 
  // mass 1,0243 e26
  // rad 24 764
  // 4 452 940 833
  //speed 5.439
  pl[7] = new planet("neptun", 24 * 3, 10243000, -5.439, 0, 0, 4452 * nearK );
  gmsManager.add(pl[7]);

  obj = new gameobj();
  pos = new positionProperty(obj);
  obj->connectProperty(pos);
  cam = new camera(obj);
  cam->set(0,-149 * nearK - 100);
  obj->connectProperty(cam);
  gmsManager.add(obj);
}

// world gravitation
void game::updateGame() {
  if (quitB->isPressed()) {
    isrunning = false;
  }

  if (darwLines->isPressed()) {
    draw = !draw;
  }

  if ( teleport->isPressed())
  {
    pla->setPos(-cam->getX() + w / 2, -cam->getY() + h / 2);
  }
  


  if (nextP->isPressed()) {
    if (onP == 8)
    {
      onP = 0;
    }else
    {
      onP++;
    }
    cam->set(-pl[onP]->getPosX() + w / 2,-pl[onP]->getPosY() + h /2);
    nextP->press();
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (i != j) {
        double x1 = pl[j]->getPosX();
        double y1 = pl[j]->getPosY();

        double x2 = pl[i]->getPosX();
        double y2 = pl[i]->getPosY();

        double hypotenuse = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (hypotenuse != 0) {
          double potence = gravity * (pl[i]->getMass()) / pow(hypotenuse, 2);

          double xVel = (-(x1 - x2) / hypotenuse * potence);
          double yVel = (-(y1 - y2) / hypotenuse * potence);
          if (pl[j]->isGravit()) {
            pl[j]->addVel(xVel, yVel);
          }
        }
      }
    }
    pl[i]->collide();
  }
}

void game::specificRenderBefore() {
  if (draw) {
    for (int i = 0; i < 9; i++) {
      for (int j = i; j < 9; j++) {
        if (i != j) {
          double x1 = pl[j]->getGlobX();
          x1 += pl[j]->getSize() / 2;
          double y1 = pl[j]->getGlobY();
          y1 += pl[j]->getSize() / 2;

          double x2 = pl[i]->getGlobX();
          x2 += pl[i]->getSize() / 2;
          double y2 = pl[i]->getGlobY();
          y2 += pl[i]->getSize() / 2;

          SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
          SDL_RenderDrawLine(getRenderer(), x1, y1, x2, y2);
        }
      }
    }
  }
}

void game::specificRenderAfter() {}