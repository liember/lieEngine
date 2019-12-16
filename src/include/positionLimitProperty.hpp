#pragma once

#include "gravityProperty.hpp"
#include "positionProperty.hpp"
#include "property.hpp"
#include "speedProperty.hpp"

class positionLimitProperty : public property {
private:
  positionProperty *pos;
  speedProperty *vel;

  double *limYbot;
  double *limYtop;
  double *limXleft;
  double *limXriht;

  void set(double **var, double s);

public:
  double getBot();
  double getTop();
  double getLeftWall();
  double getRightWall();

  void update();
  void draw();

  bool nearBot();
  bool nearTop();
  bool nearLeft();
  bool nearRight();

  bool checkBot(double p);
  bool checkTop(double p);
  bool checkLeft(double p);
  bool checkRight(double p);

  void setBot(double s);
  void setTop(double s);
  void setLeft(double s);
  void setRight(double s);

  positionLimitProperty(PropertyControlSystem *pcs);
  ~positionLimitProperty();
};
