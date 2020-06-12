#pragma once

#include "object.hpp"
#include "positionProperty.hpp"

namespace propertyes
{
  class speed final : public property
  {
  private:
    propertyes::position *pos;
    int update_status;

  public:
    speed(position *p);

    double x, y;

    ~speed() override;
    int GetType() override;
    void Update() override;
    int GetUpdateStatus() override;
  };
} // namespace propertyes