#include "InputHandler.h"
#include <Novice.h>

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
  pressKeyA_ = new MoveLeftCommand();
}
void InputHandler::AssignMoveRightCommand2PressKeyD() {
  pressKeyD_ = new MoveRightCommand();
}

ICommand *InputHandler::HandleInput() {
  if (Novice::CheckHitKey(DIK_A)) {
    return pressKeyA_;
  }
  if (Novice::CheckHitKey(DIK_D)) {
    return pressKeyD_;
  }
  return nullptr;
}