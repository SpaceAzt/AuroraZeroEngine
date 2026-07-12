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


#include "GodotFileProvider.h"
#include "GodotTimeProvider.h"

#include "EngineBootstrap.h"

static GodotTimeProvider g_timeProvider;
static GodotFileProvider g_fileProvider;

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
	// Legacy Platform Layer
	// -------------------------------------------------------------------------

	AuroraPlatform::Initialize();

	AuroraPlatform::SetTimeProvider(
			&g_timeProvider);

	AuroraPlatform::SetFileProvider(
			&g_fileProvider);

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

	AuroraPlatform::Shutdown();

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
