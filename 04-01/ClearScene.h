#pragma once
#include "IScene.h"

class ClearScene : public IScene {
private:
public:
  ClearScene(InputManager *input) : IScene(input) {}

  void Init() override;
  void Update() override;
  void Draw() override;
};