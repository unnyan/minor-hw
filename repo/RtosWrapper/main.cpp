#include "rtos.hpp"         // for Rtos
#include "mailbox.hpp"      // for Mailbox
#include "event.hpp"        // for Event
#include "LedTask.hpp"      // for LedTask
#include "appconfig.h"      // for led1, 2, 3, 4;
#include "mutex.hpp"        // for mutex

#include "rccregisters.hpp"   // for RCC

#include "Application/Diagnostic/GlobalStatus.hpp"
#include "gpioaregisters.hpp"  // for GPIOA
#include "gpiocregisters.hpp"  // for GPIOC
#include "adccommonregisters.hpp" // for ADC_Common
#include "adc1registers.hpp"    // for ADC


std::uint32_t SystemCoreClock = 16'000'000U;


extern "C" {
  int __low_level_init(void)
  {
    //Switch on external 16 MHz oscillator
    RCC::CR::HSION::On::Set();
    while (RCC::CR::HSIRDY::NotReady::IsSet())
    {

    }
    
    //Switch system clock on external oscillator
    RCC::CFGR::SW::Hsi::Set();
    while (!RCC::CFGR::SWS::Hsi::IsSet())
    {

    }
    
    //Switch on clock on PortA and PortC
    RCC::AHB1ENRPack<
        RCC::AHB1ENR::GPIOCEN::Enable,
        RCC::AHB1ENR::GPIOAEN::Enable
    >::Set();
    
    //Switch on clock for ADC
    RCC::APB2ENRPack<
        RCC::APB2ENR::ADC1EN::Enable,        
        RCC::APB2ENR::SYSCFGEN::Enable
    >::Set();
    
    //Switch on temp reader
    ADC_Common::CCR::TSVREFE::Enable::Set();
    
    //ADC Config
    ADC1::CR1::RES::Bits12::Set();
    ADC1::SQR1::L::Conversions1::Set();
    ADC1::SQR3::SQ1::Channel18::Set();
    ADC1::SMPR1::SMP18::Cycles84::Set();
    
    ADC1::CR2::CONT::SingleConversion::Set();
    ADC1::CR2::EOCS::SingleConversion::Set();
    
    //LED1 on PortA.5, set PortA.5 as output
    GPIOA::MODER::MODER5::Output::Set();

    /* LED2 on PortC.9, LED3 on PortC.8, LED4 on PortC.5 so set PortC.5,8,9 as output */
    GPIOC::MODERPack<
        GPIOC::MODER::MODER5::Output,
        GPIOC::MODER::MODER8::Output,
        GPIOC::MODER::MODER9::Output
    >::Set();
    
    return 1;
  }
}

int main()
{
  using namespace OsWrapper;
  Rtos::CreateThread(ledManagerTask, "ledManagerTask");
  Rtos::CreateThread(buttonTask, "buttonTask", OsWrapper::ThreadPriority::aboveNormal);
  Rtos::CreateThread(measureTask, "measureTask");
  Rtos::Start();

  return 0;
}
