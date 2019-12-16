#include "includer.hpp"

void textProperty::init(const char *t) {
  getTextureText(t);
  correctTexture();
}

void textProperty::SetSize(int w, int h) {
  dstrect.w = w;
  dstrect.h = h;
}

void textProperty::correctTexture() {
  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  dstrect = {0, 0, texW, texH};
}

void textProperty::update() {
  dstrect.x = pos->getOnlyX();
  dstrect.y = pos->getOnlyY();
}

void textProperty::draw() {
  SDL_Rect buf;
  buf.x = pos->getX();
  buf.y = pos->getY() - 50;
  buf.w = dstrect.w;
  buf.h = dstrect.h;
  if (texture) {
    texturemanager::draw(texture, buf);
  }
}

void textProperty::getTextureText(const char *t) {
  texture = SDL_CreateTextureFromSurface(game::getRenderer(), makeText(t));
}

textProperty::textProperty(PropertyControlSystem *pcs) {
  pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  setID(PROPERY_TEXT);
}

textProperty::~textProperty() {}