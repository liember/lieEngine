#include "include/gravityProperty.hpp"
#include "include/property.hpp"
#include "include/speedProperty.hpp"

#include <iostream>

gravityProperty::gravityProperty(PropertyControlSystem *pcs)
    : property(PROPERTY_GRAVITY)
{
  std::cout << "[?] New gravity has added" << std::endl;
  speed = static_cast<speedProperty *>(pcs->getProperty(PROPERTY_SPEED));
  Ygravity = 0.3;
}

gravityProperty::~gravityProperty() {}

void gravityProperty::setY(double x, double y)
{
  Ygravity = y;
  Xgravity = x;
}

void gravityProperty::update()
{

  speed->set(speed->getX() + Xgravity, speed->getY() + Ygravity);
}

void gravityProperty::draw() {}