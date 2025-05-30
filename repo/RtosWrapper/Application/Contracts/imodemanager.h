#pragma once

class IModeManager
{
public:
  virtual void Init() = 0; 
  virtual void SetNextMode() = 0;
  virtual void Update() = 0;
  
};