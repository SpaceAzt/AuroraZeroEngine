/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MemoryModuleTests.cpp
 *
 * Description:
 *      Memory module tests.
 ******************************************************************************/

#include "AuroraLogger.h"
#include "MemoryModule.h"

// -----------------------------------------------------------------------------
// Memory Module Tests
// -----------------------------------------------------------------------------

void RunMemoryModuleTests() {
	AuroraLogger::Section(
			"Memory Module Tests");

	MemoryModule memory;

	// -------------------------------------------------------------------------
	// Initial State
	// -------------------------------------------------------------------------

	if (memory.GetState() == EngineState::Created) {
		AuroraLogger::Success(
				"Initial state correct.");
	} else {
		AuroraLogger::Error(
				"Initial state incorrect.");
	}

	if (!memory.IsInitialized()) {
		AuroraLogger::Success(
				"Module starts uninitialized.");
	} else {
		AuroraLogger::Error(
				"Module should not be initialized.");
	}

	// -------------------------------------------------------------------------
	// Initialize
	// -------------------------------------------------------------------------

	if (memory.Initialize()) {
		AuroraLogger::Success(
				"Initialization successful.");
	} else {
		AuroraLogger::Error(
				"Initialization failed.");
	}

	if (memory.IsInitialized()) {
		AuroraLogger::Success(
				"Module initialized.");
	} else {
		AuroraLogger::Error(
				"Module initialization state incorrect.");
	}

	if (memory.GetState() == EngineState::Running) {
		AuroraLogger::Success(
				"Running state correct.");
	} else {
		AuroraLogger::Error(
				"Running state incorrect.");
	}

	// -------------------------------------------------------------------------
	// Memory Manager
	// -------------------------------------------------------------------------

	MemoryManager &manager =
			memory.GetMemoryManager();

	(void)manager;

	AuroraLogger::Success(
			"MemoryManager accessible.");

	// -------------------------------------------------------------------------
	// Update
	// -------------------------------------------------------------------------

	memory.Update();

	AuroraLogger::Success(
			"Update executed.");

	// -------------------------------------------------------------------------
	// Shutdown
	// -------------------------------------------------------------------------

	memory.Shutdown();

	if (!memory.IsInitialized()) {
		AuroraLogger::Success(
				"Shutdown successful.");
	} else {
		AuroraLogger::Error(
				"Shutdown failed.");
	}

	if (memory.GetState() == EngineState::Stopped) {
		AuroraLogger::Success(
				"Stopped state correct.");
	} else {
		AuroraLogger::Error(
				"Stopped state incorrect.");
	}
}
