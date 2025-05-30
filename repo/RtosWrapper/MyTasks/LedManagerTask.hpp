#pragma once
#include "thread.hpp"      // for thread.h
#include "imodemanager.h"  // for imodemanager
#include "ButtonTask.h"
#include "mailbox.hpp"

class LedManagerTask : public OsWrapper::Thread<256U>
{
public:
  
  LedManagerTask (IModeManager& mode, 
              const std::chrono::milliseconds delay, 
              OsWrapper::MailBox<bool, 1U>& mailBox) 
          : mDelay(delay), mMode(mode), mMailBox(mailBox)
  { 
  }
  void Execute() override;
  
private:
  const std::chrono::milliseconds mDelay;
  IModeManager& mMode;
  OsWrapper::MailBox<bool, 1U>& mMailBox;
};