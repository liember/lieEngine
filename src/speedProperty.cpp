#include "speedProperty.hpp"

using namespace propertyes;

speed::speed(position *p)
{
  pos = p;
}

speed::~speed()
{
}

int speed::GetType()
{
  return type::Speed;
}

int speed::GetUpdateStatus()
{
  return update_status;
}

void speed::Update()
{
  pos->x += x;
  pos->y += y;
}
