#include "positionProperty.hpp"

using namespace propertyes;

position::~position() {}
int position::GetType()
{
  return type::Position;
}
void position::Update()
{
  throw Except("Position property cant be updateable");
}
int position::GetUpdateStatus()
{
  return status::Passive;
}