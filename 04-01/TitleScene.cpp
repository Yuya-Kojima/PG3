#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Init() {}

void TitleScene::Update() {

  // スペースでステージへ
  if (input_->isTrigger(DIK_SPACE)) {
    sceneNo = STAGE;
  }
}

void TitleScene::Draw() {
  Novice::ScreenPrintf(100, 100, "TITLE");
  Novice::ScreenPrintf(100, 140, "Press SPACE to START");
}
