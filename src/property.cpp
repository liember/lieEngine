#include "include/property.hpp"

int property::getID() { return id; }
void property::setID(int i)
{
    id = i;
}

property::property(const property &cp)
{
    id = cp.id;
}

property::property(int i)
{
    id = i;
}

property::property()
{
}

property::~property()
{
}