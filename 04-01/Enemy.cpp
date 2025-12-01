#include "Enemy.h"

Enemy::Enemy() : isAlive_(true), x_(640), y_(100) {}

void Enemy::Draw() {
  if (!isAlive_)
    return;

  Novice::DrawEllipse(x_, y_, 20, 20, 0.0f, 0xff0000ff, kFillModeSolid);
}
