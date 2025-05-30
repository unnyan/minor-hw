#pragma once


class IAdcManager
{
public:
  virtual void TurnOn() = 0;
  virtual void StartConversion() = 0;
  virtual void WaitEndOfConvertion() = 0;
};