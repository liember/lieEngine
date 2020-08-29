#include "core.hpp"
#include "view_core.hpp"

#include <iostream>

int main(void)
{
  lieEngine::View::Window win("lieEngine", 640, 480);
  std::vector<lieEngine::Object *> *list = new std::vector<lieEngine::Object *>();
  while (win.running())
  {
    win.EventUpdate();
    win.Render(list);
  }

  return 0;
}