#include "../include/AuroraTestModule.h"

#include "../include/AuroraLogger.h"

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

	return true;
}

void AuroraTestModule::Update() {
	static int counter = 0;

	++counter;

	if (counter % 60 == 0) {
		AuroraLogger::Info("AuroraTestModule Update");
	}
}

void AuroraTestModule::Shutdown() {
	AuroraLogger::Info("AuroraTestModule Shutdown");
}
