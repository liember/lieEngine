
#include "include/objectsManager.hpp"
#include "include/gameobj.hpp"
#include <vector>

using namespace std;

objectsManager::objectsManager(/* args */) {}

objectsManager::~objectsManager() {}

void objectsManager::update()
{
  for (size_t i = 0; i < objekts.size(); i++)
  {
    if (objekts[i]->isLife)
    {
      objekts[i]->update();
    }
    else
    {
      delete objekts[i];
      objekts.erase(objekts.begin() + i);
    }
  }
}

void objectsManager::destroy()
{
  for (gameobj *n : objekts)
  {
    delete n;
  }
  objekts.clear();
}

void objectsManager::draw()
{
  for (gameobj *n : objekts)
  {
    n->draw();
  }
}

void objectsManager::add(gameobj *p) { objekts.push_back(p); }

void objectsManager::remove(gameobj *p)
{
  int i = 0;
  for (gameobj *n : objekts)
  {
    if (n == p)
    {
      delete n;
      objekts.erase(objekts.begin() + i);
    }
    i++;
  }
}

gameobj *objectsManager::get(const char *tag)
{
  for (gameobj *n : objekts)
  {
    if (strcmp(tag, n->getTag()) == 0)
    {
      return n;
    }
  }
  return nullptr;
}