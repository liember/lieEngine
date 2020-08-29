#include "core.hpp"
#include <iostream>

int main()
{
  lieEngine::Core gae;

  int counter = 1;
  int update_draw_list_delay = 30;
  std::vector<lieEngine::Object *> *draw = gae.GetDrawList();

  while (gae.running())
  {
    gae.Update();

    if (counter >= update_draw_list_delay)
    {
      counter = 1;
      delete draw;
      draw = gae.GetDrawList();
    }
    else
    {
      counter++;
    }
  }
}