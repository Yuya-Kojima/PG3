#include "Enemy.h"

int main() {

  Enemy enemy;

  for (int i = 0; i < Enemy::Phase_Count; ++i) {
    enemy.Update();
  }

  return 0;
}
