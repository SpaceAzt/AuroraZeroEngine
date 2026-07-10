#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EngineContext.h
 *
 * Description:
 *      Shared engine context.
 ******************************************************************************/

#include "EngineState.h"
#include "ModuleManager.h"

class EngineContext {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	EngineContext();

	~EngineContext();

	// -------------------------------------------------------------------------
	// Access
	// -------------------------------------------------------------------------

	[[nodiscard]]
	ModuleManager &GetModuleManager();

	[[nodiscard]]
	const ModuleManager &GetModuleManager() const;

	// -------------------------------------------------------------------------
	// State
	// -------------------------------------------------------------------------

	[[nodiscard]]
	EngineState GetEngineState() const;

	void SetEngineState(
			EngineState state);

private:
	ModuleManager m_moduleManager;

	EngineState m_engineState =
			EngineState::Created;
};
