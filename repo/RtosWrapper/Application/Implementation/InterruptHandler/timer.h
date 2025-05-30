#pragma once
#include "gpiocregisters.h"

class TimerHandlers
{
public:
  static void Tim2Handler()
  {
    GPIOC::ODR::Toggle(1 << 8U);
  }
}