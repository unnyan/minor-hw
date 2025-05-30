#pragma once
#include "gpiocregisters.hpp"
#include "tim2registers.hpp"

class TimerHandler
{
public:
  inline static volatile bool IsDelayComplete = false;
  
  static void Tim2Handler()
  {
    if (TIM2::SR::UIF::InterruptPending::IsSet() and TIM2::DIER::UIE::Enable::IsSet())
    {
      TIM2::SR::UIF::NoInterruptPending::Set();
      IsDelayComplete = true;
    }
  }
};