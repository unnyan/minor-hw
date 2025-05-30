#pragma once
#include "imode.h" //for imode class
#include <array>   // for std::size

template<auto& leds>
class TreeMode : public IMode
{
public: 
  void Init() override
  {
    currentLedIndex = 0;
    for(auto i = 0; i < std::size(leds); ++i)
    {
      leds[i] -> SwitchOff();
    }
  }
  
  void Execute() override
  {
    
    leds[currentLedIndex]->Toggle();
    
    ++currentLedIndex;
    
    if (currentLedIndex >= std::size(leds))
    {
      currentLedIndex = 0;
    }
  }
private:
  std::uint32_t currentLedIndex = 0;

};