#include "core.hpp"
#include <iostream>

int main()
{
    core *gae = new core();
    while (gae->IsRunning())
    {
        gae->Update();
    }
}