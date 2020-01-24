#include "pcs.hpp"

#include "propertyes/click_area_property/clickAreaProperty.hpp"
#include "propertyes/mouse_property/mouse.hpp"
#include "propertyes/position_property/positionProperty.hpp"
#include "propertyes/property/property.hpp"
#include "propertyes/speed_property/speedProperty.hpp"
#include "propertyes/text_property/textProperty.hpp"
#include "propertyes/texture_property/textureProperty.hpp"

void PropertyControlSystem::update()
{
  for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
  {
    if (properties[i])
    {
      properties[i]->update();
    }
  }
}

PropertyControlSystem::PropertyControlSystem(const PropertyControlSystem &cp)
{
  for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
  {
    if (properties[i])
    {
      properties[i] = cp.properties[i];
    }
  }
}

void PropertyControlSystem::draw()
{
  for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
  {
    if (properties[i])
    {
      properties[i]->draw();
    }
  }
}

property *PropertyControlSystem::addProperty(int id) // safity adding property
{
  if (!properties[id])
  {
    properties[id] = create(id);
  }
  return properties[id];
}

property *PropertyControlSystem::connectProperty(property *p) // unsafe
{
  int id = p->getID();
  if (properties[id])
  {
  }
  else
  {
    properties[id] = p;
  }
  return properties[id];
}

property *PropertyControlSystem::getProperty(int id)
{
  if (properties[id])
  {
  }
  else
  {
    std::cout << "[!] Property not created, creating new property "
              << std::endl;
    properties[id] = create(id);
  }
  return properties[id];
}

PropertyControlSystem::PropertyControlSystem(/* args */)
{
  for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
  {
    if (properties[i])
    {
      properties[i] = nullptr;
    }
  }
  std::cout << "[?] Has been created new property control system" << std::endl;
}

PropertyControlSystem::~PropertyControlSystem()
{
  for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
  {
    if (properties[i])
    {
      delete properties[i];
    }
  }
}

property *PropertyControlSystem::create(int id)
{
  switch (id)
  {
  case PROPERTY_POSITION:
    return new positionProperty(this);
    break;
  case PROPERTY_TEXTURE:
    return new textureProperty(this);
    break;
  case PROPERTY_SPEED:
    return new speedProperty(this);
    break;
  case PROPERTY_COLLIDER:
    return nullptr;
    break;
  case PROPERTY_MOUSE:
    return new mouse(this);
    break;
  case PROPERY_TEXT:
    return new textProperty(this);
    break;
  case PROPERTY_BUTTON:
    return new clickAreaProperty(this);
    break;
  default:
    return nullptr;
    break;
  }
  return nullptr;
}
