#include "includer.hpp"

buttonProperty::buttonProperty(PropertyControlSystem *pcs) {
  delay = 0.1;
  time = 0;
  fill = false;
  setID(PROPERTY_BUTTON);
  pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  m = static_cast<mouse *>(pcs->getProperty(PROPERTY_MOUSE));
  text = static_cast<textProperty *>(pcs->getProperty(PROPERY_TEXT));
  pos->setGUsing(false);
  but.h = 0;
  but.w = 0;
  but.x = 0;
  but.y = 0;
}

buttonProperty::~buttonProperty() {}

void buttonProperty::setSize(int w, int h) {
  but.w = w;
  but.h = h;
}

bool buttonProperty::isPressed() { return fill; }

void buttonProperty::setPos(double x, double y) {
  pos->setX(x);
  pos->setY(y);
}

void buttonProperty::draw() {
  SDL_Rect b;
  b.x = pos->getOnlyX() - paddingX;
  b.y = pos->getOnlyY() - paddingY;
  b.w = but.w;
  b.h = but.h;

  if (fill) {
    SDL_SetRenderDrawColor(game::getRenderer(), 80, 80, 80, 0);
    SDL_RenderFillRect(game::getRenderer(), &b);
    SDL_SetRenderDrawColor(game::getRenderer(), 0, 0, 0, 0);

  }else{
  SDL_SetRenderDrawColor(game::getRenderer(), 80, 80, 80, 0);
  SDL_RenderDrawRect(game::getRenderer(), &b);
  SDL_SetRenderDrawColor(game::getRenderer(), 0, 0, 0, 0);
  }
}

void buttonProperty::update() {
  but.x = pos->getOnlyX() - paddingX;
  but.y = pos->getOnlyY() - paddingY;
  if (m->isClicked()) {
    if (m->getx() > but.x && m->getx() < but.x + but.w) {
      if (m->gety() > but.y && m->gety() < but.y + but.h) {
        if (timer::timeout(time, delay)) {
          time = timer::GetCurrentTime();
          fill = !fill;
        }
      }
    }
  }
}
