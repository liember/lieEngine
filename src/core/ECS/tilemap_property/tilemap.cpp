#include "include/pcs.hpp"
#include "include/positionProperty.hpp"
#include "include/texturemanager.hpp"
#include "include/tilemapProperty.hpp"

#include <iostream>

int lvl[10][10] = {
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {1, 1, 1, 1, 1, 2, 2, 2, 2, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

tilemap::tilemap(PropertyControlSystem *pcs)
{
  setID(PROPERTY_TILEMAP);
  std::cout << "[?] New tilemap property added" << std::endl;
  pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  pos->setX(0);
  pos->setY(0);
  x = pos->getX();
  y = pos->getY();
  dirt = texturemanager::loadTexture("assets/dirt.png");
  grass = texturemanager::loadTexture("assets/grass.png");
  water = texturemanager::loadTexture("assets/water.png");

  loadMap(lvl);
  tile_size = 80;

  src.x = src.y = 0;
  src.w = src.h = dest.h = dest.w = tile_size;
}

tilemap::~tilemap() {}

void tilemap::loadMap(int arr[10][10])
{
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t z = 0; z < 10; z++)
    {
      map[i][z] = arr[i][z];
    }
  }
}

void tilemap::draw()
{
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t z = 0; z < 10; z++)
    {

      dest.x = z * tile_size + x;
      dest.y = i * tile_size + y;

      switch (map[i][z])
      {
      case 0:
        texturemanager::draw(water, src, dest);
        break;

      case 1:
        texturemanager::draw(grass, src, dest);
        break;
      case 2:
        texturemanager::draw(dirt, src, dest);
        break;
      default:
        break;
      }
    }
  }
}

void tilemap::update()
{
  x = pos->getX();
  y = pos->getY();
}

void tilemap::setTileSize(int s)
{
  tile_size = s;
  src.w = src.h = dest.h = dest.w = tile_size;
}

void tilemap::setPos(int xp, int yp)
{
  y = yp;
  x = xp;
}