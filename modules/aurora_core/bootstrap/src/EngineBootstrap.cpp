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
#include "ModuleManager.h"

namespace {

// -----------------------------------------------------------------------------
// Core Modules
// -----------------------------------------------------------------------------

LoggingModule g_loggingModule;

MemoryModule g_memoryModule;

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

	return true;
}

// -----------------------------------------------------------------------------

void EngineBootstrap::UnregisterModules(
		EngineContext &context) {
	ModuleManager &moduleManager =
			context.GetModuleManager();

	// -------------------------------------------------------------------------
	// Reverse Registration Order
	// -------------------------------------------------------------------------

	moduleManager.UnregisterModule(
			&g_memoryModule);

	moduleManager.UnregisterModule(
			&g_loggingModule);
}
