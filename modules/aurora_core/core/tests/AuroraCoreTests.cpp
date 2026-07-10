/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      AuroraCoreTests.cpp
 *
 * Description:
 *      Aurora core tests.
 ******************************************************************************/

#include "AuroraLogger.h"

#include "AuroraCore.h"

// -----------------------------------------------------------------------------
// Aurora Core Tests
// -----------------------------------------------------------------------------

void RunAuroraCoreTests() {
	AuroraLogger::Section(
			"Aurora Core Tests");

	AuroraCore &engine =
			AuroraCore::Get();

	// -------------------------------------------------------------------------
	// Initial State
	// -------------------------------------------------------------------------

	if (!engine.IsInitialized()) {
		AuroraLogger::Success(
				"Engine starts uninitialized.");
	} else {
		AuroraLogger::Error(
				"Engine should not be initialized.");
	}

	if (!engine.IsRunning()) {
		AuroraLogger::Success(
				"Engine starts stopped.");
	} else {
		AuroraLogger::Error(
				"Engine should not be running.");
	}

	// -------------------------------------------------------------------------
	// Initialize
	// -------------------------------------------------------------------------

	if (engine.Initialize()) {
		AuroraLogger::Success(
				"Engine initialized.");
	} else {
		AuroraLogger::Error(
				"Engine initialization failed.");
	}

	if (engine.IsInitialized()) {
		AuroraLogger::Success(
				"Initialization state correct.");
	} else {
		AuroraLogger::Error(
				"Initialization state incorrect.");
	}

	if (engine.IsRunning()) {
		AuroraLogger::Success(
				"Running state correct.");
	} else {
		AuroraLogger::Error(
				"Running state incorrect.");
	}

	// -------------------------------------------------------------------------
	// Update
	// -------------------------------------------------------------------------

	engine.Update();

	AuroraLogger::Success(
			"Update executed.");

	// -------------------------------------------------------------------------
	// Stop
	// -------------------------------------------------------------------------

	engine.Stop();

	if (!engine.IsRunning()) {
		AuroraLogger::Success(
				"Engine stopped.");
	} else {
		AuroraLogger::Error(
				"Stop failed.");
	}

	// -------------------------------------------------------------------------
	// Shutdown
	// -------------------------------------------------------------------------

	engine.Shutdown();

	if (!engine.IsInitialized()) {
		AuroraLogger::Success(
				"Shutdown successful.");
	} else {
		AuroraLogger::Error(
				"Shutdown failed.");
	}
}
