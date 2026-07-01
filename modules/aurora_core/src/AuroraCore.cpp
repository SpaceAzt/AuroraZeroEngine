#include "../include/AuroraCore.h"
#include "../include/AuroraVersion.h"
#include "../include/AuroraLogger.h"
#include "../include/AuroraFileSystem.h"

#include <iostream>

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

	 AuroraVersion::Print();


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
}

void AuroraCore::Shutdown() {
	if (!m_initialized) {
		return;
	}

	AuroraLogger::Info("Aurora Core Shutdown");

	m_initialized = false;
}

