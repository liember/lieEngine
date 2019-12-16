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

// planets
planet *pl[10];

buttonProperty *quitB;
buttonProperty *darwLines;
bool draw = false;

double gravity = 0.0000000000667408;

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

  //############ player ##############

  playerShip *pla = new playerShip();
  pla->setPos(900, 450);
  pla->setTex("assets/bird.png");
  pla->setVel(0.3, 3);
  pla->setMass(1);
  pla->setSize(50);
  pla->setSpeed(0.01);
  gmsManager.add(pla);
  pl[3] = pla;

  //############ sun ##############
  // mass 1,989 e30
  // rad 695510
  pl[0] = new planet("sun", 100, 19890000, 0, 0, 0, 0, "assets/sun.png");
  gmsManager.add(pl[0]);

  //############ planets ##############
  // mnercury
  // mass 3,285 e23
  // rad 2439,7
  //~~58 000 000
  pl[1] = new planet("mercury", 48, 3285, 0, -480, 0, 116);
  gmsManager.add(pl[1]);

  // venus
  // mass 4,867 e24
  // rad 6051,7
  //~~108 000 000
  pl[2] = new planet("venus", 120, 4867, 0, -35, 0, 216);
  gmsManager.add(pl[2]);

  // earth
  // mass 5,972 e24
  // rad 6371
  // 149 600 000
  pl[3] = new planet("earth", 126, 5972, 0, -30, 0, 300);
  gmsManager.add(pl[3]);

  // mars
  // mass 6,39 e23
  // rad 3 389,5
  // 228 000 000
  pl[4] = new planet("venus", 66, 639, 0, -24, 0, 456);
  gmsManager.add(pl[4]);

  obj = new gameobj();
  pos = new positionProperty(obj);
  obj->connectProperty(pos);
  cam = new camera(obj);
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

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
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
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
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