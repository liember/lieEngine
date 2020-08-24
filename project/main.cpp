#include "core.hpp"
#include <iostream>

int main()
{
  Core::MinimalCore gae;

  while (gae.running())
  {
    gae.Update();
  }
}