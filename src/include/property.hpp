#pragma once

//ну я хз как это без макроса мудрить
#define OVERAL_PROPERTIES 12

#define PROPERTY_POSITION 0
#define PROPERTY_TEXTURE 1
#define PROPERTY_SPEED 2
#define PROPERTY_WASD_CONTROLLER 3
#define PROPERTY_COLLIDER 4
#define PROPERTY_TILEMAP 5
#define PROPERTY_GRAVITY 6
#define PROPERTY_CAMERA 7
#define PROPERTY_POSITION_LIMIT 8
#define PROPERTY_MOUSE 9
#define PROPERY_WASD_ANIMATOR 10
#define PROPERY_TEXT 12
#define PROPERTY_BUTTON 11

class property
{
private:
  int id;

public:
  virtual void draw() = 0;
  virtual void update() = 0;

  int getID();
  void setID(int i);

  property *self();

  property();
  property(int i);
  property(const property &cp);
  virtual ~property();
};
