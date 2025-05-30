#include <iostream> // for std::cout, endl
#include "ButtonTask.h"
//#include "criticalsection.hpp" // for crit sec


void ButtonTask::Execute()
{
  for (;;)
  {
    //mLockCoutMutex.Lock();
    //OsWrapper::CriticalSection criticalSection;
    /*
    std::cout << "buttonTask: ";
    for (int i = 0; i <= 10; ++i)
    {
      std::cout << "buttonTask: " << i;
    }
    std::cout << std::endl;
    */

    if (mButton.IsPressed())
    {
      mMailBox.Put(true);
    }
    //mLockCoutMutex.UnLock();

    Sleep(mDelay);
  }
}
