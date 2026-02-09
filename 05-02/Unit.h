#pragma once
#include <Novice.h>

class Selector;

class Unit {
public:
  void Init(int id);

  void Draw() const;

  void Move(int x, int y);
  void MoveEnd(Selector *selector);

  void SetSelected(bool v);
  bool IsSelected() const;

  int GetX() const;
  int GetY() const;

private:
  int mapX_ = 10;
  int mapY_ = 8;
  int mapSize_ = 32;
  int id_ = 0;
  bool isSelected_ = false;
  unsigned int color_ = WHITE;
  int drawSize_ = 24;
};