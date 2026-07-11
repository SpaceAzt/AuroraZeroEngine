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
#include "MemoryModule.h"

static GodotTimeProvider g_timeProvider;
static GodotFileProvider g_fileProvider;

static MemoryModule g_memoryModule;

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

	AuroraTime::Initialize();

	// -------------------------------------------------------------------------
	// Register Engine Modules
	// -------------------------------------------------------------------------

	ModuleManager &moduleManager =
			m_context.GetModuleManager();

	moduleManager.RegisterModule(
			&g_memoryModule);

	// -------------------------------------------------------------------------
	// Initialize Modules
	// -------------------------------------------------------------------------

	moduleManager.InitializeModules();

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
