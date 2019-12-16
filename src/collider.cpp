#include "includer.hpp"

std::vector<colliderProperty *> colliderProperty::colliders;

PropertyControlSystem *colliderProperty::getPcs() { return p; }

colliderProperty::colliderProperty(PropertyControlSystem *pcs) {
  setID(PROPERTY_COLLIDER);
  p = pcs;
  pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  colliders.push_back(this);
}

colliderProperty::~colliderProperty() {
  std::vector<colliderProperty *>::const_iterator it =
      find(colliders.begin(), colliders.end(), this);
  colliders.erase(it);
}

bool colliderProperty::detect(SDL_Rect b) {
  int left = std::max(body.x, b.x);
  int top = std::min(body.y + body.h, b.y + b.h);
  int right = std::min(body.x + body.w, b.x + b.w);
  int bottom = std::max(body.y, b.y);

  int width = right - left;
  int height = top - bottom;

  if (width <= 0 || height <= 0)
    return false;

  return true;
}

PropertyControlSystem *colliderProperty::findCollision() {
  for (colliderProperty *c : colliders) {
    if (c != this) {
      if (detect(c->getBody())) {
        return c->getPcs();
      }
    }
  }
  return nullptr;
}

void colliderProperty::setDraw(bool b) { drawBody = b; }

void colliderProperty::draw() {
  SDL_Rect bufRect = body;
  bufRect.x = pos->getX();
  bufRect.y = pos->getY();
  if (drawBody) {
    SDL_SetRenderDrawColor(game::getRenderer(), 0, 0, 0, 0);
    SDL_RenderDrawRect(game::getRenderer(), &bufRect);
    SDL_SetRenderDrawColor(game::getRenderer(), 255, 255, 255, 0);
  }
}

void colliderProperty::update() {
  body.x = pos->getOnlyX();
  body.y = pos->getOnlyY();
}

SDL_Rect colliderProperty::getBody() { return body; }

void colliderProperty::setBody(int w, int h) {
  body.w = w;
  body.h = h;
}