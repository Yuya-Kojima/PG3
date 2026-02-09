#pragma once
#include "IStageSceneCommand.h"

class Selector;

class SelectorMoveCommand : public IStageSceneCommand {
public:
  SelectorMoveCommand(Selector *selector, int x, int y)
      : selector_(selector), x_(x), y_(y) {}
  void Exec() override;

private:
  Selector *selector_ = nullptr;
  int x_ = 0;
  int y_ = 0;
};

class SelectUnitCommand : public IStageSceneCommand {
public:
  SelectUnitCommand(Selector *selector) : selector_(selector) {}
  void Exec() override;

private:
  Selector *selector_ = nullptr;
};