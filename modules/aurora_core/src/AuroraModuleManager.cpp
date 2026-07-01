#include "../include/AuroraModuleManager.h"
#include "../include/IAuroraModule.h"
#include "../include/AuroraLogger.h"


std::vector<std::shared_ptr<IAuroraModule>>
		AuroraModuleManager::m_modules;

void AuroraModuleManager::Initialize() {
	AuroraLogger::Success("Aurora Module Manager Initialized");

	for (auto &module : m_modules) {
		if (!module->Initialize()) {
			AuroraLogger::Error("Module initialization failed.");
		}
	}
}

void AuroraModuleManager::Update() {
	for (auto &module : m_modules) {
		module->Update();
	}
}

void AuroraModuleManager::Shutdown() {
	for (auto it = m_modules.rbegin();
			it != m_modules.rend();
			++it) {
		(*it)->Shutdown();
	}

	AuroraLogger::Info("Aurora Module Manager Shutdown");

	m_modules.clear();
}

void AuroraModuleManager::RegisterModule(
		std::shared_ptr<IAuroraModule> module) {
	if (!module) {
		AuroraLogger::Error("Cannot register null module.");
		return;
	}

	m_modules.push_back(module);
}
