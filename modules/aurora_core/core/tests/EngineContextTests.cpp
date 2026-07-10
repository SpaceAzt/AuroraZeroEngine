/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EngineContextTests.cpp
 ******************************************************************************/

#include "AuroraLogger.h"

#include "EngineContext.h"

// -----------------------------------------------------------------------------
// Engine Context Tests
// -----------------------------------------------------------------------------

void RunEngineContextTests() {
	AuroraLogger::Section(
			"Engine Context Tests");

	EngineContext context;

	// -------------------------------------------------------------------------
	// Initial State
	// -------------------------------------------------------------------------

	if (context.GetEngineState() ==
			EngineState::Created) {
		AuroraLogger::Success(
				"Initial engine state correct.");

	} else {
		AuroraLogger::Error(
				"Initial engine state incorrect.");
	}

	// -------------------------------------------------------------------------
	// State Change
	// -------------------------------------------------------------------------

	context.SetEngineState(
			EngineState::Running);

	if (context.GetEngineState() ==
			EngineState::Running) {
		AuroraLogger::Success(
				"Engine state updated.");

	} else {
		AuroraLogger::Error(
				"Engine state update failed.");
	}

	// -------------------------------------------------------------------------
	// Module Manager
	// -------------------------------------------------------------------------

	if (context.GetModuleManager()
					.GetModuleCount() == 0) {
		AuroraLogger::Success(
				"Module manager available.");

	} else {
		AuroraLogger::Error(
				"Unexpected module count.");
	}
}
