#include "LedManagerTask.hpp"
#include "mailbox.hpp"
#include "ButtonTask.h"
#include <iostream> // for std::cout, endl
#include "LedManagerTask.hpp"

void LedManagerTask::Execute()
{
  for (;;)
  {
    
    
    /*
    mLockCoutMutex.Lock();
    std::cout << "modeManagerTask: ";
    for (char i = 33; i <= 133; ++i)
    {
      std::cout << "modeManagerTask: " << i;
    }
    std::cout << std::endl;
    */
    
    bool isPressed = false;
    if (mMailBox.Get(isPressed, mDelay))
    {  
      if (isPressed)
      {
        mMode.SetNextMode();
      }
    }
    mMode.Update();
    
    
    //mLockCoutMutex.UnLock();
    Sleep(mDelay);
  }
}