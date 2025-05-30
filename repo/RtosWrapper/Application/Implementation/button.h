#pragma once
#include "ibutton.h" //for IButton

template<std::size_t registerAddress, std::uint32_t pinNumber, bool isPullUp = true>
class Button : public IButton
{
public:
    bool IsPressed() override
    {
      auto const ptrGpioIdr =
        reinterpret_cast<volatile std::uint32_t*>(registerAddress); 
      if constexpr (isPullUp)
      {
        return (*ptrGpioIdr & (1U << pinNumber)) != (1U << pinNumber);
      }
      else 
      {
        return (*ptrGpioIdr & (1U << pinNumber)) == (1U << pinNumber);
      }
    }
};