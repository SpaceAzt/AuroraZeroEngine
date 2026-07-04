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

	void RunSparseSetTests();

	void RunComponentStorageTests();

	void RunRegistryComponentTests();

	void RunViewTests();

	void RunMultiViewTests();

	void RunSystemManagerTests();

	void RunMovementSystemTests();

	void RunCommandBufferTests();

	void RunECSTests();

	void RunEventSystemTests();



};
