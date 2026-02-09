#pragma once

class Selector;
class Unit;
class IStageSceneCommand;

class StageSceneInputHandler {
public:
  void UpdateKeyState();

  IStageSceneCommand *SelectorHandleInput(Selector *selector);
  IStageSceneCommand *UnitHandleInput(Unit *unit, Selector *selector);

private:
  char keys_[256] = {0};
  char preKeys_[256] = {0};
};