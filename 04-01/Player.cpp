#include "Player.h"

void Player::Update() {
  isShot_ = false;
  if (input_->isTrigger(DIK_SPACE)) {
    isShot_ = true;
  }

  if (input_->isPress(DIK_A)) {
    x_--;
  } else if (input_->isPress(DIK_D)) {
    x_++;
  }
}

void Player::Draw() {
  Novice::DrawEllipse(x_, y_, 15, 15, 0.0f, 0xffffffff, kFillModeSolid);
}
