#include "includer.hpp"

wather *cam;
spaceBody *pl[10];

button *quitB;
button *darwLines;
bool draw = false;
button *nextP;
int onP = 0;
button *teleport;

double gravity = 0.0000667408;
int nearK = 70;

void game::initGame()
{

  wather *obj = new wather(3000 - w / 2, 3000 - h / 2);
  gmsManager.add(obj);

  //############ player ##############
  pl[8] = new playerShip("player", 40, 3000, 3000, 0, 0, "assets/b2.png");
  gmsManager.add(pl[8]);

  //############ Solar system initialisation ##############
  //############ Sun ##############
  // mass 1,989 e30
  // rad 695510
  pl[0] = new spaceBody("sun", 695, 198900000, 0, 0, 0, 0, "assets/sun.png");
  gmsManager.add(pl[0]);
  // Mercury
  // mass 3,285 e23
  // rad 2439,7
  //Перигелий	46 001 009 км
  // speed 48
  pl[1] = new spaceBody("mercury", 2 * 3, 3285, -48, 0, 0, 46 * nearK, "assets/mercury.png");
  pl[1]->setTextColor(255, 255, 255);
  gmsManager.add(pl[1]);
  // Venus
  // mass 4,867 e24
  // rad 6051,7
  //~~108 000 000
  // speed 35
  pl[2] = new spaceBody("venus", 6 * 3, 4867, -35, 0, 0, 108 * nearK, "assets/venus.png");
  pl[2]->setTextColor(255, 255, 255);
  gmsManager.add(pl[2]);
  // Earth
  // mass 5,972 e24
  // rad 6371
  // 149 600 000
  // speed 30
  pl[3] = new spaceBody("earth", 6 * 3, 5972, -30, 0, 0, 149 * nearK, "assets/earth.png");
  pl[3]->setTextColor(255, 255, 255);
  gmsManager.add(pl[3]);
  // Mars
  // mass 6,39 e23
  // rad 3 389,5
  // 228 000 000
  // speed 24.13
  pl[4] = new spaceBody("mars", 2 * 3, 639, -24.13, 0, 0, 228 * nearK, "assets/mars.png");
  pl[4]->setTextColor(255, 255, 255);
  gmsManager.add(pl[4]);
  // Jupiter
  // mass 1.898 e27
  // rad 69 911.5
  // 778,57 000 000
  // speed 24.13
  pl[5] = new spaceBody("jupiter", 69 * 3, 18980000, -13, 0, 0, 778 * nearK, "assets/jupiter.png");
  pl[5]->setTextColor(255, 255, 255);
  gmsManager.add(pl[5]);
  // Uran
  // mass 8,6813⋅10 e25
  // rad 25 559
  // 2,8 000 000 000
  // speed 6.81
  pl[6] = new spaceBody("uran", 25 * 3, 8681300, -6.81, 0, 0, 2800 * nearK, "assets/uran.png");
  pl[6]->setTextColor(255, 255, 255);
  gmsManager.add(pl[6]);
  // Neptun
  // mass 1,0243 e26
  // rad 24 764
  // 4 452 940 833
  // speed 5.439
  pl[7] = new spaceBody("neptun", 24 * 3, 10243000, -5.439, 0, 0, 4452 * nearK, "assets/neptun.png");
  pl[7]->setTextColor(255, 255, 255);
  gmsManager.add(pl[7]);
  //############ menu ##############
  //############ quit
  quitB = new button(30, 580, "Quit");
  gmsManager.add(quitB);
  //########### drawL
  darwLines = new button(260, 580, "DrawLines");
  gmsManager.add(darwLines);
  //########### nextPlanet
  nextP = new button(490, 580, "Next Player");
  gmsManager.add(nextP);
  //########### teleport
  teleport = new button(720, 580, "Teleport player");
  gmsManager.add(teleport);
}

void game::updateGame()
{
  if (quitB->isClecked())
  {
    isrunning = false;
    darwLines->press();
  }

  if (darwLines->isClecked())
  {
    draw = !draw;
    darwLines->press();
  }

  if (teleport->isClecked())
  {
    pl[8]->setPos(-cam->getPosX() + w / 2, -cam->getPosY() + h / 2);
  }

  if (nextP->isClecked())
  {
    if (onP == 8)
    {
      onP = 0;
    }
    else
    {
      onP++;
    }
    cam->setPos(-pl[onP]->getPosX() + w / 2, -pl[onP]->getPosY() + h / 2);
    nextP->press();
  }

  // world gravitation
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (i != j)
      {
        double x1 = pl[j]->getPosX();
        double y1 = pl[j]->getPosY();

        double x2 = pl[i]->getPosX();
        double y2 = pl[i]->getPosY();

        double hypotenuse = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (hypotenuse != 0)
        {
          double potence = gravity * (pl[i]->getMass()) / pow(hypotenuse, 2);

          double xVel = (-(x1 - x2) / hypotenuse * potence);
          double yVel = (-(y1 - y2) / hypotenuse * potence);
          if (pl[j]->isGravit())
          {
            pl[j]->addVel(xVel, yVel);
          }
        }
      }
    }
    if (pl[i]->collide())
    {
      pl[i]->setTextColor(255, 0, 0);
    }
  }
}

void game::specificRenderBefore()
{
  if (draw)
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = i; j < 9; j++)
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

          SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
          SDL_RenderDrawLine(getRenderer(), x1, y1, x2, y2);
        }
      }
    }
  }
}

void game::specificRenderAfter() {}