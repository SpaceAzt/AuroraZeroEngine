/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      CoreTests.cpp
 *
 * Description:
 *      Core module test runner.
 ******************************************************************************/

#include "AuroraLogger.h"

// Forward declarations
void RunAuroraCoreTests();
void RunEngineContextTests();
void RunModuleManagerTests();

// -----------------------------------------------------------------------------
// Core Tests
// -----------------------------------------------------------------------------

void RunCoreTests() {
	AuroraLogger::Section(
			"Core Tests");

	RunAuroraCoreTests();

	RunEngineContextTests();

	RunModuleManagerTests();
}
