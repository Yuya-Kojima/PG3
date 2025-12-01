#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Init() {}

void ClearScene::Update() {

  // スペースでタイトルに戻る
  if (input_->isTrigger(DIK_SPACE)) {
    sceneNo = TITLE;
  }
}

void ClearScene::Draw() {
  Novice::ScreenPrintf(100, 100, "CLEAR");
  Novice::ScreenPrintf(100, 140, "Press SPACE to TITLE");
}