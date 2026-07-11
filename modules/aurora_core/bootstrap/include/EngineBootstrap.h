#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EngineBootstrap.h
 *
 * Description:
 *      Registers and configures engine modules.
 ******************************************************************************/

class EngineContext;

class EngineBootstrap {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	EngineBootstrap();

	~EngineBootstrap();

	// -------------------------------------------------------------------------
	// Bootstrap
	// -------------------------------------------------------------------------

	bool RegisterModules(
			EngineContext &context);

	void UnregisterModules(
			EngineContext &context);
};
