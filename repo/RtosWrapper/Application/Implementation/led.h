#pragma once
#include "iledtoggleable.h" //for iledtoggleable

template<std::size_t registerAddress, std::uint32_t pinNumber>
class Led : public ILedToggleable
{
public:
    void Toggle() override
    {
      auto const ptrGpioOdr =
        reinterpret_cast<volatile std::uint32_t*>(registerAddress); 
      *ptrGpioOdr ^= (1U << pinNumber);
    }
    void SwitchOff() override
    {
      auto const ptrGpioOdr =
        reinterpret_cast<volatile std::uint32_t*>(registerAddress); 
      *ptrGpioOdr &= ~(1U << pinNumber);
    }
};