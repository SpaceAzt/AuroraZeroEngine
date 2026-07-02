#include "../include/AuroraTestModule.h"

#include "../include/AuroraLogger.h"

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

	return true;
}

void AuroraTestModule::Update() {
	// Şimdilik boş.
}

void AuroraTestModule::Shutdown() {
	AuroraLogger::Info("AuroraTestModule Shutdown");
}
