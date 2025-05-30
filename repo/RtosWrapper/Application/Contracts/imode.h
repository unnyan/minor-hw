#pragma once

class IMode
{
public:
  virtual void Execute() = 0;
  virtual void Init() = 0;
};