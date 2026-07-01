#include "../include/AuroraCore.h"
#include "../include/AuroraVersion.h"

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


	std::cout << "[Aurora] Core Initialize\n";

	m_initialized = true;

	return true;
}

void AuroraCore::Update() {
}

void AuroraCore::Shutdown() {
	if (!m_initialized) {
		return;
	}

	std::cout << "[Aurora] Core Shutdown\n";

	m_initialized = false;
}

