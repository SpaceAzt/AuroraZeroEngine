/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EngineBootstrap.cpp
 *
 * Description:
 *      Registers engine modules.
 ******************************************************************************/

#include "EngineBootstrap.h"

#include "EngineContext.h"

#include "LoggingModule.h"
#include "MemoryModule.h"
#include "TimeModule.h"

#include "ModuleManager.h"

namespace {

// -----------------------------------------------------------------------------
// Core Modules
// -----------------------------------------------------------------------------

LoggingModule g_loggingModule;

MemoryModule g_memoryModule;

TimeModule g_timeModule;

} // namespace

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

EngineBootstrap::EngineBootstrap() = default;

// -----------------------------------------------------------------------------

EngineBootstrap::~EngineBootstrap() = default;

// -----------------------------------------------------------------------------
// Bootstrap
// -----------------------------------------------------------------------------

bool EngineBootstrap::RegisterModules(
		EngineContext &context) {
	ModuleManager &moduleManager =
			context.GetModuleManager();

// -------------------------------------------------------------------------
	// Level 0
	// Logging
	// -------------------------------------------------------------------------

	if (!moduleManager.RegisterModule(
				&g_loggingModule)) {
		return false;
	}

	// -------------------------------------------------------------------------
	// Level 1
	// Memory
	// -------------------------------------------------------------------------

	if (!moduleManager.RegisterModule(
				&g_memoryModule)) {
		return false;
	}

	// -------------------------------------------------------------------------
	// Level 2
	// Time
	// -------------------------------------------------------------------------

	if (!moduleManager.RegisterModule(
				&g_timeModule)) {
		return false;
	}

	return true;
}

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Bootstrap
// -----------------------------------------------------------------------------

void EngineBootstrap::UnregisterModules(
		EngineContext &context) {
	ModuleManager &moduleManager =
			context.GetModuleManager();

	// -------------------------------------------------------------------------
	// Reverse Registration Order
	// -------------------------------------------------------------------------

	moduleManager.UnregisterModule(
			&g_timeModule);

	moduleManager.UnregisterModule(
			&g_memoryModule);

	moduleManager.UnregisterModule(
			&g_loggingModule);
}
