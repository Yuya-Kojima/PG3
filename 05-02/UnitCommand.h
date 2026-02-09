#pragma once
#include "IStageSceneCommand.h"

class Unit;
class Selector;

class UnitMoveCommand : public IStageSceneCommand {
public:
  UnitMoveCommand(Unit *unit, int x, int y) : unit_(unit), x_(x), y_(y) {}
  void Exec() override;

private:
  Unit *unit_ = nullptr;
  int x_ = 0;
  int y_ = 0;
};

class UnitMoveEndCommand : public IStageSceneCommand {
public:
  UnitMoveEndCommand(Unit *unit, Selector *selector)
      : unit_(unit), selector_(selector) {}
  void Exec() override;

private:
  Unit *unit_ = nullptr;
  Selector *selector_ = nullptr;
};