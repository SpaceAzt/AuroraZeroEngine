#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EntityCommandBuffer.h
 *
 * Description:
 *      Stores deferred ECS commands.
 ******************************************************************************/

#include "ecs/commands/ICommand.h"

#include <memory>
#include <vector>

class Registry;

class EntityCommandBuffer {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	EntityCommandBuffer();

	~EntityCommandBuffer();

	// -------------------------------------------------------------------------
	// Commands
	// -------------------------------------------------------------------------

	void Enqueue(std::unique_ptr<ICommand> command);

	// -------------------------------------------------------------------------
	// Execution
	// -------------------------------------------------------------------------

	void Flush(Registry &registry);

private:
	// -------------------------------------------------------------------------
	// Command Storage
	// -------------------------------------------------------------------------

	std::vector<std::unique_ptr<ICommand>> m_commands;
};
