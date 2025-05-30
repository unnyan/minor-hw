#pragma once

template <typename T>
class IDataProvider
{
public:
  virtual T GetData() = 0;
};