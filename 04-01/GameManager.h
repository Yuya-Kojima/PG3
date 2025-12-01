#pragma once

#include "ClearScene.h"
#include "IScene.h"
#include "InputManager.h"
#include "StageScene.h"
#include "TitleScene.h"
#include <memory>

class GameManager {

private:
  std::unique_ptr<IScene> sceneArr_[3];

  int currentSceneNo_;

  int prevSceneNo_;

  InputManager *inputManager_ = nullptr;

public:
  GameManager(InputManager *inputManager);
  ~GameManager();

  int Run();
};
