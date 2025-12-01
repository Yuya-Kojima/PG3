#pragma once
#include <Novice.h>

class Enemy {
private:
  bool isAlive_;
  int x_;
  int y_;

public:
  Enemy();

  void Init(int x, int y) {
    x_ = x;
    y_ = y;
    isAlive_ = true;
  }
  void Update();
  void Draw();
  bool GetIsAlive() const { return isAlive_; }
  void Kill() { isAlive_ = false; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
};
