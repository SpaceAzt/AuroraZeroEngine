#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      CreateEntityCommand.h
 *
 * Description:
 *      Deferred entity creation command.
 ******************************************************************************/

#include "ecs/commands/ICommand.h"

class CreateEntityCommand : public ICommand {
public:
	// -------------------------------------------------------------------------
	// Execute
	// -------------------------------------------------------------------------

	void Execute(Registry &registry) override;
};
