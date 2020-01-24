#pragma once

#include "../../property_manager/pcs.hpp"
#include <string.h>
#include <iostream>

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
