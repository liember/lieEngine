#pragma once

#include "object.hpp"
#include "MyException.hpp"

namespace propertyes
{
  class position : public property
  {
  public:
    float x;
    float y;

    ~position() override;
    int GetType() override;
    void Update() override;
    int GetUpdateStatus() override;
  };
} // namespace propertyes