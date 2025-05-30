#pragma once
#include "thread.hpp" // for thread.h
#include "ibutton.h" // for IButton
#include "mailbox.hpp"
//#include "mutex.hpp"

class ButtonTask : public OsWrapper::Thread<256U>
{
public:
  ButtonTask(IButton& button, 
             const std::chrono::milliseconds delay,
             OsWrapper::MailBox<bool, 1U>& mailBox
             //OsWrapper::Mutex& lockCoutMutex
               )
    : mDelay(delay), mButton(button), mMailBox(mailBox)//, mLockCoutMutex(lockCoutMutex)
  {
    
  }
  
  void Execute() override;
  
private:
  const std::chrono::milliseconds mDelay;
  IButton& mButton;
  OsWrapper::MailBox<bool, 1U>& mMailBox;
  //OsWrapper::Mutex mLockCoutMutex;
};
