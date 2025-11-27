#include "Enemy.h"
#include <stdio.h>

void (Enemy::*Enemy::stateFunc[Phase_Count])() = {
    &Enemy::Approach,
    &Enemy::Shoot,
    &Enemy::Escape,
};

void Enemy::Update() { (this->*stateFunc[phase])(); }

void Enemy::Approach() {
  printf("敵は接近している...\n");
  phase = Phase_Shoot;
}

void Enemy::Shoot() {
  printf("敵は射撃している！\n");
  phase = Phase_Escape;
}

void Enemy::Escape() { printf("敵は離脱している...\n"); }