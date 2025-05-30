#pragma once

class ILedToggleable
{
  public:
    virtual void Toggle() = 0;
    virtual void SwitchOff() = 0;
};
