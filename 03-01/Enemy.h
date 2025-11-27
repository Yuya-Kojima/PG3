#pragma once

class Enemy {

public:
  enum Phase {
    Phase_Approach,
    Phase_Shoot,
    Phase_Escape,
    Phase_Count,
  };

  void Update();

  void Approach();

  void Shoot();

  void Escape();

private:
  Phase phase = Phase_Approach;

  static void (Enemy::*stateFunc[Phase_Count])();
};
