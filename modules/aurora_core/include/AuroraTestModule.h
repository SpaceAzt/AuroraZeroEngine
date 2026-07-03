#pragma once

#include "IAuroraModule.h"

class AuroraTestModule : public IAuroraModule {
public:
	bool Initialize() override;

	void Update() override;

	void Shutdown() override;

private:
	// -------------------------------------------------------------------------
	// Test Suites
	// -------------------------------------------------------------------------

	void RunEventSystemTests();

	void RunComponentStorageTests();

	void RunECSTests();

	 void RunSparseSetTests();

};
