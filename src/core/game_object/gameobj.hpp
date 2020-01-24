#pragma once

#include "../ECS/property_contol_system/pcs.hpp"
#include <string.h>

class gameobj : public PropertyControlSystem
{
private:
  char *tag;

public:
  bool isLife;

  gameobj(const gameobj &gameobj);

  char *getTag();
  gameobj(const char *name);
  gameobj();
  ~gameobj();
};
