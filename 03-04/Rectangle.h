#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
  float w, h;

public:
  Rectangle(float width, float height) : w(width), h(height) {}

  float Size() override { return w * h; }

  void Draw() override { cout << "長方形の面積: " << Size() << endl; }
};
