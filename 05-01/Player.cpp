#include "Player.h"
#include <Novice.h>

Player::Player() {}

void Player::Init() {}

void Player::Update() {}

void Player::Draw() {
  Novice::DrawBox((int)posX_, (int)posY_, 50, 50, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight() { posX_ += speed_; }
void Player::MoveLeft() { posX_ -= speed_; }