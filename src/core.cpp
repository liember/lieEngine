#include "core.hpp"

using namespace std;

SDL_Renderer *game::renderer = nullptr;
SDL_Window *game::window = nullptr;

SDL_Event game::event;

game::game(/* args */) {}

game::~game()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  TTF_Quit();
}

void game::initEngine(const char *title, int xpos, int ypos, int width,
                      int height, bool windowed)
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
    TTF_Init();
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

  initGame();
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
  updateGame();
}

void game::render()
{
  SDL_SetRenderDrawColor(renderer, 20, 20, 30, 0);
  SDL_RenderClear(renderer);
  specificRenderBefore();
  specificRenderAfter();
  SDL_RenderPresent(renderer);
}

void game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

bool game::running() { return isrunning; }

SDL_Renderer *game::getRenderer() { return renderer; }

SDL_Window *game::getWindow() { return window; }