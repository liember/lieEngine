#pragma once

#include "propertyes/property/property.hpp"
#include "../texture_manager/texturemanager.hpp"
#include "../core.hpp"

class PropertyControlSystem
{
private:
  property *properties[OVERAL_PROPERTIES + 1];

  int getPropertyID(property *p);
  property *create(int id);

public:
  PropertyControlSystem(/* args */);
  PropertyControlSystem(const PropertyControlSystem &PropertyControlSystem);

  ~PropertyControlSystem();

  void update();
  void destroy();
  void draw();

  PropertyControlSystem *self() { return this; }

  property *addProperty(int id);
  property *connectProperty(property *p);

  property *getProperty(int id);
};