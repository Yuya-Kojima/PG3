#pragma once
#include "InputManager.h"

enum Scene { TITLE, STAGE, CLEAR };

class IScene {

protected:
  static int sceneNo;

  InputManager *input_;

public:
  IScene(InputManager *input) : input_(input) {}
  virtual ~IScene() {}

  virtual void Init() = 0;
  virtual void Update() = 0;
  virtual void Draw() = 0;

  int GetSceneNo() const { return sceneNo; }
};
