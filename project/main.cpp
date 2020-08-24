#include "core.hpp"
#include "view_core.hpp"

#include <iostream>

int main()
{
  Core::MinimalCore gae;
  Core::View::Window *win = new Core::View::Window("LieEngine v2.3", 300, 200, 1200, 700, false);

  while (gae.running() && win->running())
  {
    win->EventUpdate();
    gae.Update();

    win->Render(gae.GetDrawList());
  }
}