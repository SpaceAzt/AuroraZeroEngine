#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      DestroyEntityCommand.h
 *
 * Description:
 *      Deferred entity destruction command.
 ******************************************************************************/

#include "ecs/Entity.h"
#include "ecs/commands/ICommand.h"

class DestroyEntityCommand : public ICommand {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	explicit DestroyEntityCommand(Entity entity);

	// -------------------------------------------------------------------------
	// Execute
	// -------------------------------------------------------------------------

	void Execute(Registry &registry) override;

private:
	Entity m_entity;
};
