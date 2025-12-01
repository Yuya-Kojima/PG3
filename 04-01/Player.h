#pragma once
#include "InputManager.h"
#include <Novice.h>

class Player {

private:
  InputManager *input_ = nullptr;
  int x_;
  int y_;
  bool isShot_ = false;

public:
  Player(InputManager *input) : input_(input), x_(640), y_(650) {}

  void Update();
  bool GetIsShot() const { return isShot_; }
  void Draw();
  int GetX() const { return x_; }
  int GetY() const { return y_; }
};