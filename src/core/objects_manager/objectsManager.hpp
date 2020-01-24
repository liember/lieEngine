#ifndef _OBJECTS_MANGER_
#define _OBJECTS_MANGER_

#include "game_object/game_object.hpp"

#include <iostream>
#include <vector>

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

#endif