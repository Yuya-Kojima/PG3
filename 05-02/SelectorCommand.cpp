#include "SelectorCommand.h"
#include "Selector.h"

void SelectorMoveCommand::Exec() { selector_->Move(x_, y_); }

void SelectUnitCommand::Exec() { selector_->SelectUnit(); }