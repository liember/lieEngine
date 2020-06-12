#pragma once

namespace propertyes
{

  enum status
  {
    Active,
    Passive
  };

  enum type
  {
    Position,
    Speed,
    Mass,
    Lifetime
  };

  class property
  {
  public:
    virtual ~property() {}
    virtual int GetType() = 0;
    virtual void Update() = 0;
    virtual int GetUpdateStatus() = 0;
  };

} // namespace propertyes