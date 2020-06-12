#pragma once

#include "MyException.hpp"
#include "property.hpp"

#include <map>
#include <memory>
#include <vector>

class object;

typedef std::unique_ptr<propertyes::property> prop_ptr;
typedef std::map<int, prop_ptr> property_collection;

typedef std::shared_ptr<object> obj_ptr;
typedef std::unique_ptr<object> unique_obj;

class object
{
protected:
  property_collection active_properties;
  property_collection passive_properties;

  std::vector<unique_obj> childs;

public:
  void KillChilds();
  void AddChild(unique_obj obj);

  void Update();

  void AddProperty(prop_ptr p);
  prop_ptr StealProperty(int id);
};
