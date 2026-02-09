#pragma once
#include "Command.h"

class InputHandler {
public:
  void AssignMoveLeftCommand2PressKeyA();
  void AssignMoveRightCommand2PressKeyD();

  ICommand *HandleInput();

private:
  ICommand *pressKeyA_ = nullptr;
  ICommand *pressKeyD_ = nullptr;
};
