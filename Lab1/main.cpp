#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp" // for GPIOA
#include "gpiocregisters.hpp" // for GPIO�

std::uint32_t SystemCoreClock = 16'000'000U;

extern "C" {
int __low_level_init(void)
{
  //Switch on external 16 MHz oscillator
  RCC::CR::HSEON::On::Set();
  while (RCC::CR::HSERDY::NotReady::IsSet())
  {

  }
  //Switch system clock on external oscillator
  RCC::CFGR::SW::Hse::Set();
  while (!RCC::CFGR::SWS::Hse::IsSet())
  {

  }
  
  RCC::APB2ENR::SYSCFGEN::Enable::Set();

  return 1;
}
}

void delay(int cycles)
{
  for(int i = 0; i < cycles; ++i)    
  {   
    asm volatile("");
  }    
}

int main()
{  
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOAEN::Enable::Set() ;
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOCEN::Enable::Set() ;
  //����� �.5 �� �����
  GPIOA::MODER::MODER5::Output::Set() ;
  //����� C.5,C.8, C.9 �� �����
  GPIOC::MODER::MODER5::Output::Set() ;
  GPIOC::MODER::MODER8::Output::Set() ;
  GPIOC::MODER::MODER9::Output::Set() ;
  
  for(;;)
  {
   
     GPIOA::ODR::ODR5::High::Set();
     GPIOC::ODR::ODR5::High::Set();
     delay(1000000); 
     GPIOA::ODR::ODR5::Low::Set();
     GPIOC::ODR::ODR5::Low::Set();
     delay(1000000); 
  }
  
  return 1;
}
