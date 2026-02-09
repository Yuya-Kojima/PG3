#include "Unit.h"
#include "Selector.h"

void Unit::Init(int id) { id_ = id; }

void Unit::Draw() const {
  int offset = (mapSize_ - drawSize_) / 2;

  if (isSelected_) {
    Novice::DrawBox(mapX_ * mapSize_ + offset, mapY_ * mapSize_ + offset,
                    drawSize_, drawSize_, 0.0f, 0xFFB6C1FF, kFillModeSolid);
  } else {
    Novice::DrawBox(mapX_ * mapSize_ + offset, mapY_ * mapSize_ + offset,
                    drawSize_, drawSize_, 0.0f, color_, kFillModeSolid);
  }
}

void Unit::Move(int x, int y) {
  mapX_ += x;
  mapY_ += y;
}

void Unit::MoveEnd(Selector * /*selector*/) { isSelected_ = false; }

void Unit::SetSelected(bool v) { isSelected_ = v; }

bool Unit::IsSelected() const { return isSelected_; }

int Unit::GetX() const { return mapX_; }

int Unit::GetY() const { return mapY_; }
