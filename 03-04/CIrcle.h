#pragma once
#include "IShape.h"

class Circle : public IShape {

private:
  float radius;

public:
  Circle(float r) : radius(r) {}

  float Size() override { return 3.14 * radius * radius; }

  void Draw() override { cout << "円の面積: " << Size() << endl; }
};
