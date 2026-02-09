#include "Selector.h"
#include "Unit.h"

void Selector::Init(Unit *units, int unitCount) {
  unit_ = units;
  unitCount_ = unitCount;
  selectedUnit_ = nullptr;
  selectMode_ = SelectMode::Selector;
}

void Selector::Draw() const {

  if (selectMode_ != SelectMode::Selector) {
    return;
  }

  Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f,
                  RED, kFillModeWireFrame);
}

void Selector::Move(int x, int y) {
  mapX_ += x;
  mapY_ += y;
}

void Selector::SelectUnit() {
  selectedUnit_ = nullptr;

  for (int i = 0; i < unitCount_; ++i) {
    if (unit_[i].GetX() == mapX_ && unit_[i].GetY() == mapY_) {
      selectedUnit_ = &unit_[i];
      selectedUnit_->SetSelected(true);
      selectMode_ = SelectMode::Unit;
      break;
    }
  }
}