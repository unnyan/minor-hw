#pragma once
#include "imode.h" //for imode class
#include <array>   // for std::size

template<auto& leds>
class ChessMode : public IMode
{
public: 
  void Init() override
  {
    for(auto i = 0; i < std::size(leds); ++i)
    {
      leds[i] -> SwitchOff();
    }
    
    for(auto i = 0; i < std::size(leds); ++i)
    {
      if ((i % 2U) == 0U)
      {
        leds[i]->Toggle();
      }
    }
  }
  void Execute() override
  {
    for(auto it: leds)
    {
      it->Toggle();
    }
  }
};