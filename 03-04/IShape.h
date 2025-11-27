#pragma once
#include <iostream>
using namespace std;

class IShape {

public:
  virtual float Size() = 0;

  virtual void Draw() = 0;
};
