#pragma once
#include <Novice.h>

class Player {
public:
  Player();

  void Init();
  void Update();
  void Draw();

  // コマンドから呼ばれる
  void MoveRight();
  void MoveLeft();

private:
  float posX_ = 640.0f;
  float posY_ = 360.0f;
  float speed_ = 5.0f;
};
