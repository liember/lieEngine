#include <SDL2/SDL.h>
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

using namespace std;

SDL_Renderer *game::renderer = nullptr;
SDL_Event game::event;

int points = 5;

void game::initGame()
{
    gameobj *obj = new gameobj();
    obj->addProperty(PROPERTY_POSITION);
    obj->addProperty(PROPERTY_SPEED);
    textureProperty *t = new textureProperty(obj);
    t->setTexture("assets/bird.png");
}

game::game(/* args */) {}

game::~game() {}

void game::initEngine(const char *title, int xpos, int ypos, int width, int height, bool windowed)
{
    h = height;
    w = width;

    gtimer = new timer(0.005);

    int flags = 0;

    if (windowed)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "[?] subsystem inited" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window)
        {
            cout << "[?] Window created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "[?] Renderer created" << endl;
        }

        isrunning = true;
    }
    else
    {
        isrunning = false;
    }
}

void game::handleevents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isrunning = false;
        break;

    default:
        break;
    }
}

int i = 0;

void game::update()
{
    gtimer->FrameTimeout();
    gtimer->deltaUpdate();

    gameobj *obj = gmsManager.get("kaktus");
    static_cast<positionProperty *>(obj->getProperty(PROPERTY_SPEED))->setX(points * -10);
    positionProperty *pos = static_cast<positionProperty *>(obj->getProperty(PROPERTY_POSITION));
    if (pos->getX() < -100)
    {
        if (points < 30)
        {
            points++;
        }

        pos->setX(900);
    }
    gmsManager.update();
}

void game::render()
{
    SDL_RenderClear(renderer);
    gmsManager.draw();
    SDL_RenderPresent(renderer);
}

void game::clean()
{
    gmsManager.destroy();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool game::running()
{
    return isrunning;
}

SDL_Renderer *game::getRenderer()
{
    return renderer;
}