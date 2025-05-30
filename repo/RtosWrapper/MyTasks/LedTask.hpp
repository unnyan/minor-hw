#pragma once
#include "thread.hpp"       // for thread.h
#include "iledtoggleable.h" // for iled
#include <chrono>           // for chrono type

class LedTask : public OsWrapper::Thread<256U>
{
public:
  void Execute() override;
  
  LedTask (ILedToggleable& led, const std::chrono::milliseconds delay) 
          : mDelay(delay), mLed(led) 
  {
  }

private:
  const std::chrono::milliseconds mDelay;
  ILedToggleable& mLed;
};