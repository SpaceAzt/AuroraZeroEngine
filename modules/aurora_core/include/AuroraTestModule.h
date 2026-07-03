#pragma once

#include "IAuroraModule.h"

class AuroraTestModule : public IAuroraModule {
public:
	bool Initialize() override;

	void Update() override;

	void Shutdown() override;

private:
	void RunEventSystemTests();

	void RunECSTests();

	 void RunSparseSetTests();

};
