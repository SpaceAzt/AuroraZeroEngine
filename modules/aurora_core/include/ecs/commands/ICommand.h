#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ICommand.h
 *
 * Description:
 *      Base interface for deferred ECS commands.
 ******************************************************************************/

class Registry;

class ICommand {
public:
	virtual ~ICommand() = default;

	// -------------------------------------------------------------------------
	// Executes the command on the registry.
	// -------------------------------------------------------------------------

	virtual void Execute(Registry &registry) = 0;
};
