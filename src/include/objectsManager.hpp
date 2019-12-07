#pragma once

#include <iostream>
#include <vector>

#include "property.hpp"
#include "gameobj.hpp"

class objectsManager
{
private:
    std::vector<gameobj *> objekts;

public:
    void add(gameobj *p);
    gameobj *get(const char *tag);

    void remove(gameobj *p);

    void update();
    void destroy();
    void draw();

    objectsManager(/* args */);
    ~objectsManager();
};