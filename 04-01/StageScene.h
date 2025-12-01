#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "IScene.h"
#include "Player.h"

class StageScene : public IScene {
private:
  Player *player_;
  Enemy *enemy_;
  Bullet bullet_;

public:
  StageScene(InputManager *input);
  ~StageScene();

  void Init() override;
  void Update() override;
  void Draw() override;
};