#pragma once

#include "pcs.hpp"
#include "property.hpp"
#include "speedProperty.hpp"

#define W_KEY 0
#define A_KEY 1
#define S_KEY 2
#define D_KEY 3
#define SPACE_KEY 4

class WASDControllerProperty : public property
{
private:
  bool keyStates[3];

public:
  WASDControllerProperty(PropertyControlSystem *pcs);
  ~WASDControllerProperty();

  bool *getStates();

  void update();
  void draw();
};
