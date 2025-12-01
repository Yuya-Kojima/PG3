#include "StageScene.h"
#include <Novice.h>

StageScene::StageScene(InputManager *input) : IScene(input) {

  player_ = new Player(input);

  enemy_ = new Enemy();
}

StageScene::~StageScene() {
  delete player_;
  delete enemy_;
}

void StageScene::Init() {
  enemy_->Init(640, 100);
  bullet_.Kill();
}

void StageScene::Update() {

  player_->Update();

  if (player_->GetIsShot() && !bullet_.IsAlive()) {
    bullet_.Spawn(player_->GetX(), player_->GetY() - 20);
  }

  bullet_.Update();

  if (enemy_->GetIsAlive() && bullet_.IsAlive()) {

    int dx = bullet_.GetX() - enemy_->GetX();
    int dy = bullet_.GetY() - enemy_->GetY();
    int r = bullet_.GetRadius() + 20;

    if (dx * dx + dy * dy <= r * r) {
      enemy_->Kill();
      bullet_.Kill();
    }
  }

  if (!enemy_->GetIsAlive()) {
    sceneNo = CLEAR;
  }
}

void StageScene::Draw() {
  Novice::ScreenPrintf(100, 100, "STAGE");
  Novice::ScreenPrintf(100, 140, "Press SPACE to CLEAR");

  player_->Draw();
  bullet_.Draw();
  enemy_->Draw();
}