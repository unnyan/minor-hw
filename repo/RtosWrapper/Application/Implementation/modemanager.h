#pragma once
#include "imodemanager.h" // for IModeManager class

template<auto& modes>
class ModeManager : public IModeManager
{
private:
  std::uint32_t i = 0;

public:
  void Init() override
  {
    modes[i]->Init();
  }

  void SetNextMode() override
  {
    const auto nexti = i + 1;
    i = (nexti >= (std::size(modes))) ? 0 : nexti;
    modes[i]->Init();
  }

  void Update() override
  {
    modes[i]->Execute();
  }
};