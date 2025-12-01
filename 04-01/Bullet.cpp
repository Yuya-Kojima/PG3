#include "Bullet.h"

Bullet::Bullet() : x_(0), y_(0), vy_(-8), radius_(5), isAlive_(false) {}

// 弾発射
void Bullet::Spawn(int x, int y) {
  x_ = x;
  y_ = y;
  vy_ = -8;
  radius_ = 5;
  isAlive_ = true;
}

// 弾の更新
void Bullet::Update() {
  if (!isAlive_)
    return;

  y_ += vy_;

  // 画面外で消える
  if (y_ < -10) {
    isAlive_ = false;
  }
}

// 弾の描画
void Bullet::Draw() const {
  if (!isAlive_)
    return;

  Novice::DrawEllipse(x_, y_, radius_, radius_, 0.0f, 0xFF00FFFF,
                      kFillModeSolid);
}