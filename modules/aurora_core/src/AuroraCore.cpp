#include "../include/AuroraCore.h"
#include "../include/AuroraPlatform.h"
#include "../include/AuroraLogger.h"
#include "../include/AuroraFileSystem.h"
#include "../include/AuroraModuleManager.h"
#include "../include/GodotTimeProvider.h"
#include "../include/AuroraTime.h"
#include "../include/AuroraTestModule.h"
#include "../include/GodotFileProvider.h"
#include "../include/events/EventBus.h"
#include "../include/events/engine/EngineStartedEvent.h"
#include "../include/events/engine/EngineStoppedEvent.h"

#include <memory>

#include <iostream>

static GodotTimeProvider g_timeProvider;
static GodotFileProvider g_fileProvider;


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
	AuroraPlatform::SetFileProvider(&g_fileProvider);

	AuroraTime::Initialize();

	AuroraModuleManager::RegisterModule(
			std::make_shared<AuroraTestModule>());

	AuroraModuleManager::Initialize();

	EngineStartedEvent started;
	EventBus::Get().Publish(started);

	AuroraLogger::Success("Aurora Core Initialized");

	 if (AuroraFileSystem::Exists("README.md")) {
		 AuroraLogger::Info("README.md bulundu.");
	 } else {
		 AuroraLogger::Warning("README.md bulunamadi.");
	 }

	m_initialized = true;
	 m_running = true;
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

	EngineStoppedEvent stopped;

	EventBus::Get().Publish(stopped);

	AuroraModuleManager::Shutdown();

	AuroraPlatform::Shutdown();
	
	AuroraLogger::Info("Aurora Core Shutdown");

	m_running = false;
	m_initialized = false;
}

bool AuroraCore::IsRunning() const {
	return m_running;
}

void AuroraCore::Stop() {
	m_running = false;
}
