#pragma once
#include <cstdint>              // for std::uint32_t
#include "idataprovider.h"      // for idataprovider (get data to adc)
#include "iadcmanager.h"        // for iadcmanager
#include "adc1registers.hpp"    //for ADC1

template <typename T>
class Adc : public IDataProvider <T>, public IAdcManager
{
public:
  T GetData() override 
  {
    return ADC1::DR::Get();
  };
  
  void TurnOn() override 
  {
    ADC1::CR2::ADON::Enable::Set();
  };
  
  void StartConversion() override
  {
    ADC1::CR2::SWSTART::On::Set();
  };
  
  void WaitEndOfConvertion() override
  {
    while (not ADC1::SR::EOC::ConversionComplete::IsSet())
    {
      
    }
  };
};