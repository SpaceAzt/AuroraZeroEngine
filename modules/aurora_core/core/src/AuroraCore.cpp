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
#include "AuroraPlatform.h"
#include "AuroraTime.h"
#include "GodotFileProvider.h"
#include "GodotTimeProvider.h"

static GodotTimeProvider g_timeProvider;
static GodotFileProvider g_fileProvider;

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

// -----------------------------------------------------------------------------

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
	// Platform
	// -------------------------------------------------------------------------

	AuroraPlatform::Initialize();

	AuroraPlatform::SetTimeProvider(
			&g_timeProvider);

	AuroraPlatform::SetFileProvider(
			&g_fileProvider);

	AuroraTime::Initialize();

	// -------------------------------------------------------------------------
	// Engine Modules
	// -------------------------------------------------------------------------

	m_context
			.GetModuleManager()
			.InitializeModules();

	m_initialized = true;

	m_running = true;

	m_context.SetEngineState(
			EngineState::Running);

	AuroraLogger::Success(
			"Aurora Engine initialized.");

	return true;
}

// -----------------------------------------------------------------------------

void AuroraCore::Update() {
	if (!m_running) {
		return;
	}

	AuroraTime::Update();

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

	AuroraPlatform::Shutdown();

	m_running = false;

	m_initialized = false;

	m_context.SetEngineState(
			EngineState::Stopped);

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
