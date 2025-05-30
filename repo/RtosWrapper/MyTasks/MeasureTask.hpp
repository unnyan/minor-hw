#pragma once
#include "thread.hpp"

class MeasureTask : public OsWrapper::Thread<256U>
{
public:
  
  
  
  void Execute() override;
private:

};