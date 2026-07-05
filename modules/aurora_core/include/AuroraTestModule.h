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
	void RunECSTests();
	void RunEventSystemTests();
	void RunMovementSystemTests();
	void RunCommandBufferTests();
	void RunComponentManagerTests();

	// -------------------------------------------------------------------------
	// Memory Tests
	// -------------------------------------------------------------------------

	void RunLinearAllocatorTests();
};
