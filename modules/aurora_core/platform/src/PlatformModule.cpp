/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      PlatformModule.cpp
 *
 * Description:
 *      Platform module implementation.
 ******************************************************************************/

#include "PlatformModule.h"

#include "AuroraLogger.h"
#include "GodotFileProvider.h"
#include "GodotTimeProvider.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

PlatformModule::PlatformModule() = default;

PlatformModule::~PlatformModule() = default;

// -----------------------------------------------------------------------------
// IModule
// -----------------------------------------------------------------------------

bool PlatformModule::Initialize() {
	if (m_initialized) {
		return true;
	}

	m_timeProvider =
			std::make_unique<GodotTimeProvider>();

	m_fileProvider =
			std::make_unique<GodotFileProvider>();

	m_platformManager.Initialize();

	m_platformManager.SetTimeProvider(
			m_timeProvider.get());

	m_platformManager.SetFileProvider(
			m_fileProvider.get());

	m_state = EngineState::Running;

	m_initialized = true;


	return true;
}

// -----------------------------------------------------------------------------

void PlatformModule::Update() {
	// Reserved for future platform updates.
}

// -----------------------------------------------------------------------------

void PlatformModule::Shutdown() {
	if (!m_initialized) {
		return;
	}

	m_platformManager.Shutdown();

	m_fileProvider.reset();

	m_timeProvider.reset();

	m_initialized = false;

	m_state = EngineState::Stopped;

	AuroraLogger::Info(
			"Platform Module shutdown.");
}

// -----------------------------------------------------------------------------

std::string_view
PlatformModule::GetName() const {
	return "Platform";
}

// -----------------------------------------------------------------------------

std::string_view
PlatformModule::GetVersion() const {
	return "1.0.0";
}

// -----------------------------------------------------------------------------

bool PlatformModule::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

EngineState
PlatformModule::GetState() const {
	return m_state;
}

// -----------------------------------------------------------------------------

PlatformManager &
PlatformModule::GetPlatformManager() {
	return m_platformManager;
}

// -----------------------------------------------------------------------------

const PlatformManager &
PlatformModule::GetPlatformManager() const {
	return m_platformManager;
}
