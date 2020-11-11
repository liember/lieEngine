#include "core.hpp"
#include "core_view.hpp"

#include <iostream>

int main(void)
{
  lieEngine::View::Window win("lieEngine", 640, 480);

  while (win.running())
  {
    win.EventUpdate();
  }

  return 0;
}