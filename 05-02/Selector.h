#pragma once
#include <Novice.h>

class Unit;

enum class SelectMode {
  Selector,
  Unit,
};

class Selector {
public:
  void Init(Unit *units, int unitCount);
  void Draw() const;

  void Move(int x, int y);
  void SelectUnit();

  SelectMode GetSelectMode() const { return selectMode_; }
  Unit *GetSelectedUnitAddress() const { return selectedUnit_; }

  void BackToSelectorMode() { selectMode_ = SelectMode::Selector; }

  void SetPos(int x, int y) {
    mapX_ = x;
    mapY_ = y;
  }

private:
  int mapX_ = 10;
  int mapY_ = 8;
  int mapSize_ = 32;

  SelectMode selectMode_ = SelectMode::Selector;

  Unit *unit_ = nullptr;
  int unitCount_ = 0;

  Unit *selectedUnit_ = nullptr;
};