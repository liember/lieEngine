#include "include/gameobj.hpp"

gameobj::gameobj(const char *name) {
  tag = new char[60];
  strcpy(tag, name);
}

char *gameobj::getTag() { return tag; }

gameobj::gameobj(const gameobj &cp) : PropertyControlSystem(cp) {
  strcpy(tag, cp.tag);
  std::cout << "[?] Create new gameobject with tag: " << tag << std::endl;
}

gameobj::gameobj() {
  std::cout << "[?] Create new gameobject without tag" << std::endl;
}

gameobj::~gameobj() { delete tag; }