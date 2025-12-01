#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager(InputManager *inputManager)
    : currentSceneNo_(TITLE), prevSceneNo_(-1), inputManager_(inputManager) {
  sceneArr_[TITLE] = std::make_unique<TitleScene>(inputManager_);
  sceneArr_[STAGE] = std::make_unique<StageScene>(inputManager_);
  sceneArr_[CLEAR] = std::make_unique<ClearScene>(inputManager_);

  sceneArr_[currentSceneNo_]->Init();
}

GameManager::~GameManager() {}

int GameManager::Run() {

  while (Novice::ProcessMessage() == 0) {
    Novice::BeginFrame();

    inputManager_->Update();

    // シーンのチェック
    prevSceneNo_ = currentSceneNo_;
    currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

    // シーン変更チェック
    if (prevSceneNo_ != currentSceneNo_) {
      sceneArr_[currentSceneNo_]->Init();
    }

    // 更新処理
    sceneArr_[currentSceneNo_]->Update();

    // 描画処理
    sceneArr_[currentSceneNo_]->Draw();

    Novice::EndFrame();

    if (inputManager_->isTrigger(DIK_ESCAPE)) {
      break;
    }
  }

  return 0;
}
