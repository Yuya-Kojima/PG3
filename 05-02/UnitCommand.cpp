#include "UnitCommand.h"
#include "Selector.h"
#include "Unit.h"

void UnitMoveCommand::Exec() { unit_->Move(x_, y_); }

void UnitMoveEndCommand::Exec() {
  unit_->MoveEnd(selector_);
  selector_->SetPos(unit_->GetX(), unit_->GetY());
  selector_->BackToSelectorMode();
}