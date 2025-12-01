#pragma once
#include "IScene.h"

class TitleScene : public IScene {
private:
public:
  TitleScene(InputManager *input) : IScene(input) {}

  void Init() override;
  void Update() override;
  void Draw() override;
};