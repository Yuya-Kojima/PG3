#pragma once
#include <Novice.h>

class Bullet {

private:
  int x_;
  int y_;
  int vy_;
  int radius_;
  bool isAlive_;

public:
  Bullet();

  void Spawn(int x, int y); // 弾を発射
  void Update();            // 移動処理
  void Draw() const;        // 描画

  bool IsAlive() const { return isAlive_; }
  void Kill() { isAlive_ = false; }

  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetRadius() const { return radius_; }
};