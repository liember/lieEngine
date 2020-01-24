#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../objects_manager/objectsManager.hpp"
#include "../game_object/gameobj.hpp"
#include "../timer/timer.hpp"

class game
{
private:
  bool isrunning;
  int cnt = 0;

  int w, h;

  static SDL_Window *window;
  static SDL_Renderer *renderer;

  objectsManager gmsManager;

  void updateGame();
  void initGame();
  void specificRenderBefore();
  void specificRenderAfter();

public:
  timer *gtimer;
  static SDL_Window *getWindow();
  static SDL_Renderer *getRenderer();
  static SDL_Event event;

  void initEngine(const char *title, int xpos, int ypos, int width, int height,
                  bool windowed);
  void handleevents();

  void update();
  void render();
  void clean();

  bool running();
  game(/* args */);
  ~game();
};
