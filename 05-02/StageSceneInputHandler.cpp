#include "StageSceneInputHandler.h"
#include <Novice.h>
#include <cstring>

#include "Selector.h"
#include "SelectorCommand.h"
#include "Unit.h"
#include "UnitCommand.h"

void StageSceneInputHandler::UpdateKeyState() {
  std::memcpy(preKeys_, keys_, 256);
  Novice::GetHitKeyStateAll(keys_);
}

IStageSceneCommand *
StageSceneInputHandler::SelectorHandleInput(Selector *selector) {

  if ((preKeys_[DIK_LEFT] == 0 && keys_[DIK_LEFT] != 0) ||
      (preKeys_[DIK_A] == 0 && keys_[DIK_A] != 0)) {
    return new SelectorMoveCommand(selector, -1, 0);
  }

  if ((preKeys_[DIK_RIGHT] == 0 && keys_[DIK_RIGHT] != 0) ||
      (preKeys_[DIK_D] == 0 && keys_[DIK_D] != 0)) {
    return new SelectorMoveCommand(selector, +1, 0);
  }

  if ((preKeys_[DIK_UP] == 0 && keys_[DIK_UP] != 0) ||
      (preKeys_[DIK_W] == 0 && keys_[DIK_W] != 0)) {
    return new SelectorMoveCommand(selector, 0, -1);
  }

  if ((preKeys_[DIK_DOWN] == 0 && keys_[DIK_DOWN] != 0) ||
      (preKeys_[DIK_S] == 0 && keys_[DIK_S] != 0)) {
    return new SelectorMoveCommand(selector, 0, +1);
  }

  if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0) {
    return new SelectUnitCommand(selector);
  }

  return nullptr;
}

IStageSceneCommand *
StageSceneInputHandler::UnitHandleInput(Unit *unit, Selector *selector) {
  if (!unit)
    return nullptr;

  if ((preKeys_[DIK_LEFT] == 0 && keys_[DIK_LEFT] != 0) ||
      (preKeys_[DIK_A] == 0 && keys_[DIK_A] != 0)) {
    return new UnitMoveCommand(unit, -1, 0);
  }

  if ((preKeys_[DIK_RIGHT] == 0 && keys_[DIK_RIGHT] != 0) ||
      (preKeys_[DIK_D] == 0 && keys_[DIK_D] != 0)) {
    return new UnitMoveCommand(unit, +1, 0);
  }

  if ((preKeys_[DIK_UP] == 0 && keys_[DIK_UP] != 0) ||
      (preKeys_[DIK_W] == 0 && keys_[DIK_W] != 0)) {
    return new UnitMoveCommand(unit, 0, -1);
  }

  if ((preKeys_[DIK_DOWN] == 0 && keys_[DIK_DOWN] != 0) ||
      (preKeys_[DIK_S] == 0 && keys_[DIK_S] != 0)) {
    return new UnitMoveCommand(unit, 0, +1);
  }

  if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0) {
    return new UnitMoveEndCommand(unit, selector);
  }

  return nullptr;
}
