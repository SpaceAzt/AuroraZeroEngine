/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      AuroraCore.cpp
 *
 * Description:
 *      Main engine core implementation.
 ******************************************************************************/

#include "AuroraCore.h"

#include "AuroraLogger.h"
#include "EngineBootstrap.h"


static EngineBootstrap g_bootstrap;

// -----------------------------------------------------------------------------
// Singleton
// -----------------------------------------------------------------------------

AuroraCore &AuroraCore::Get() {
	static AuroraCore instance;

	return instance;
}

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

AuroraCore::AuroraCore() = default;

AuroraCore::~AuroraCore() = default;

// -----------------------------------------------------------------------------
// Engine Lifecycle
// -----------------------------------------------------------------------------

bool AuroraCore::Initialize() {
	if (m_initialized) {
		return true;
	}

	m_context.SetEngineState(
			EngineState::Initializing);

	// -------------------------------------------------------------------------
	// Register Engine Modules
	// -------------------------------------------------------------------------

if (!g_bootstrap.RegisterModules(
				m_context)) {
		AuroraLogger::Error(
				"Failed to register engine modules.");

		return false;
	}

	m_context
			.GetModuleManager()
			.InitializeModules();


	m_context.SetEngineState(
			EngineState::Running);

	m_initialized = true;

	m_running = true;

	AuroraLogger::Success(
			"Aurora Engine initialized.");

	return true;
}

// -----------------------------------------------------------------------------

void AuroraCore::Update() {
	if (!m_running) {
		return;
	}

	m_context
			.GetModuleManager()
			.UpdateModules();
}

// -----------------------------------------------------------------------------

void AuroraCore::Shutdown() {
	if (!m_initialized) {
		return;
	}

	m_context.SetEngineState(
			EngineState::ShuttingDown);

	m_context
			.GetModuleManager()
			.ShutdownModules();

	g_bootstrap.UnregisterModules(
			m_context);

	m_context.SetEngineState(
			EngineState::Stopped);

	m_running = false;

	m_initialized = false;

	AuroraLogger::Info(
			"Aurora Engine shutdown.");
}

// -----------------------------------------------------------------------------

void AuroraCore::Stop() {
	m_running = false;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

bool AuroraCore::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

bool AuroraCore::IsRunning() const {
	return m_running;
}

// -----------------------------------------------------------------------------
// Context
// -----------------------------------------------------------------------------

EngineContext &
AuroraCore::GetContext() {
	return m_context;
}

// -----------------------------------------------------------------------------

const EngineContext &
AuroraCore::GetContext() const {
	return m_context;
}
