#include "../include/AuroraCore.h"
#include "../include/AuroraPlatform.h"
#include "../include/AuroraLogger.h"
#include "../include/AuroraFileSystem.h"
#include "../include/AuroraModuleManager.h"
#include "../include/GodotTimeProvider.h"
#include "../include/AuroraTime.h"
#include "../include/AuroraTestModule.h"

#include <memory>

#include <iostream>

static GodotTimeProvider g_timeProvider;
static AuroraTestModule g_testModule;

AuroraCore::AuroraCore() {
}

AuroraCore::~AuroraCore() {
}

AuroraCore &AuroraCore::Get() {
	static AuroraCore core;
	return core;
}

bool AuroraCore::Initialize() {
	if (m_initialized) {
		return true;
	}

	AuroraPlatform::Initialize();

	AuroraPlatform::SetTimeProvider(&g_timeProvider);

	AuroraTime::Initialize();

	AuroraModuleManager::RegisterModule(
			std::make_shared<AuroraTestModule>());

	AuroraModuleManager::Initialize();

	AuroraLogger::Success("Aurora Core Initialized");

	 if (AuroraFileSystem::Exists("README.md")) {
		 AuroraLogger::Info("README.md bulundu.");
	 } else {
		 AuroraLogger::Warning("README.md bulunamadi.");
	 }

	m_initialized = true;

	return true;
}

void AuroraCore::Update() {
	AuroraTime::Update();

	AuroraModuleManager::Update();
}

void AuroraCore::Shutdown() {
	if (!m_initialized) {
		return;
	}

	AuroraModuleManager::Shutdown();

	AuroraPlatform::Shutdown();
	
	AuroraLogger::Info("Aurora Core Shutdown");

	m_initialized = false;
}

