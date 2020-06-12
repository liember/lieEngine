#include "property.hpp"
#include "object.hpp"

void object::Update()
{
  for (auto &&i : active_properties)
  {
    i.second->Update();
  }
}

void object::AddProperty(prop_ptr p)
{
  int key = p->GetType();

  if (p->GetUpdateStatus() == propertyes::status::Active)
    active_properties[key] = std::move(p);
  else
    active_properties[key] = std::move(p);
}

prop_ptr object::StealProperty(int id)
{
  prop_ptr res;
  auto it = active_properties.find(id);
  if (it != active_properties.end())
  {
    res = std::move(it->second);
    active_properties.erase(it);
  }
  it = active_properties.find(id);
  if (it != passive_properties.end())
  {
    res = std::move(it->second);
    passive_properties.erase(it);
  }
  else
  {
    throw Except("Cant find property for stealing");
  }
  return res;
}

void object::KillChilds()
{
  for (auto &&i : childs)
  {
    delete i.release();
  }
}

void object::AddChild(unique_obj obj)
{
  childs.push_back(std::move(obj));
}