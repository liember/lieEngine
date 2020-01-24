#ifndef _PROPERTY_CONTROL_SYSTEM_
#define _PROPERTY_CONTROL_SYSTEM_

#include "../texture_manager/texturemanager.hpp"
#include "propertyes/property/property.hpp"

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

#endif