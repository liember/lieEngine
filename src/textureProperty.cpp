#include "include/textureProperty.hpp"
#include "include/pcs.hpp"
#include "include/texturemanager.hpp"

#include <iostream>

textureProperty::textureProperty(PropertyControlSystem *pcs)
    : property(PROPERTY_TEXTURE)
{
  position =
      static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  destR.x = (int)position->getX();
  destR.y = (int)position->getY();
  destR.w = destR.h = texSize = 64;
}

void textureProperty::setTexture(const char *path)
{
  texture = texturemanager::loadTexture(path);
}

void textureProperty::addTexture(SDL_Texture *t) { texture = t; }

void textureProperty::draw() { texturemanager::draw(texture, destR); }

textureProperty::~textureProperty() { texturemanager::destroyTexture(texture); }

void textureProperty::update()
{
  destR.x = (int)position->getX();
  destR.y = (int)position->getY();
}

void textureProperty::setTextureSize(int s) { destR.w = destR.h = texSize = s; }

void textureProperty::set(SDL_Texture *tex) { texture = tex; }

SDL_Texture *textureProperty::getTexture() { return texture; }