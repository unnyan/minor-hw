#include "MeasureTask.hpp"
#include "adc.h"
#include <iostream>

void MeasureTask::Execute()
{
  Adc<std::uint32_t> adc;
  adc.TurnOn();
  for (;;)
  {
    adc.StartConversion();
    adc.WaitEndOfConvertion();
    auto adcCode = adc.GetData();
    
    std::uint32_t tsCal1Address = 0x1FFF7A2C;
    std::uint16_t tsCal1 = *reinterpret_cast<std::uint16_t*>(tsCal1Address);
    
    std::uint32_t tsCal2Address = 0x1FFF7A2E;
    std::uint16_t tsCal2 = *reinterpret_cast<std::uint16_t*>(tsCal2Address);
    
    auto k = (110.0f - 30.0f) / static_cast<float>(tsCal2 - tsCal1);
    auto b = 110.0f - k * static_cast<float>(tsCal2);
    
    auto temp = k*adcCode + b;
    
    std::cout << temp << std::endl;
    Sleep(1s);
  }
};