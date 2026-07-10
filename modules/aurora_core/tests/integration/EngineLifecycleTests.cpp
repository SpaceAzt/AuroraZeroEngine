/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EngineLifecycleTests.cpp
 *
 * Description:
 *      Engine lifecycle integration tests.
 ******************************************************************************/

#include "AuroraLogger.h"
#include "MemoryModule.h"

#include "AuroraCore.h"

// -----------------------------------------------------------------------------
// Engine Lifecycle Tests
// -----------------------------------------------------------------------------

void RunEngineLifecycleTests() {
	AuroraLogger::Section(
			"Engine Lifecycle Tests");

	AuroraCore &engine =
			AuroraCore::Get();

	MemoryModule memory;

	// -------------------------------------------------------------------------
	// Register Module
	// -------------------------------------------------------------------------

	if (engine.GetContext()
					.GetModuleManager()
					.RegisterModule(&memory)) {
		AuroraLogger::Success(
				"Memory module registered.");

	} else {
		AuroraLogger::Error(
				"Memory module registration failed.");
	}

	// -------------------------------------------------------------------------
	// Initialize Engine
	// -------------------------------------------------------------------------

	if (engine.Initialize()) {
		AuroraLogger::Success(
				"Engine initialized.");

	} else {
		AuroraLogger::Error(
				"Engine initialization failed.");
	}

	// -------------------------------------------------------------------------
	// Verify Module Initialization
	// -------------------------------------------------------------------------

	if (memory.IsInitialized()) {
		AuroraLogger::Success(
				"Memory module initialized.");

	} else {
		AuroraLogger::Error(
				"Memory module initialization failed.");
	}

	// -------------------------------------------------------------------------
	// Update
	// -------------------------------------------------------------------------

	engine.Update();

	AuroraLogger::Success(
			"Engine update completed.");

	// -------------------------------------------------------------------------
	// Shutdown
	// -------------------------------------------------------------------------

	engine.Shutdown();

	if (!memory.IsInitialized()) {
		AuroraLogger::Success(
				"Memory module shutdown.");

	} else {
		AuroraLogger::Error(
				"Memory module shutdown failed.");
	}

	// -------------------------------------------------------------------------
	// Unregister Module
	// -------------------------------------------------------------------------

	if (engine.GetContext()
					.GetModuleManager()
					.UnregisterModule(&memory)) {
		AuroraLogger::Success(
				"Memory module unregistered.");

	} else {
		AuroraLogger::Error(
				"Memory module unregister failed.");
	}
}
