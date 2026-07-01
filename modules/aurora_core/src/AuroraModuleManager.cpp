#include "../include/AuroraModuleManager.h"

#include "../include/AuroraConfig.h"
#include "../include/AuroraLogger.h"
#include "../include/AuroraVersion.h"

void AuroraModuleManager::Initialize() {
	AuroraVersion::Print();

	AuroraLogger::Success("Aurora Module Manager Initialized");

	AuroraConfig::Load("aurora.cfg");
}

void AuroraModuleManager::Shutdown() {
	AuroraLogger::Info("Aurora Module Manager Shutdown");
}
