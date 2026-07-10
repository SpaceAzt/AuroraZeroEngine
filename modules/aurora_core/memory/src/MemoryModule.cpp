/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MemoryModule.cpp
 *
 * Description:
 *      Aurora memory engine module implementation.
 ******************************************************************************/

#include "MemoryModule.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

MemoryModule::MemoryModule() = default;

// -----------------------------------------------------------------------------

MemoryModule::~MemoryModule() = default;

// -----------------------------------------------------------------------------
// Lifecycle
// -----------------------------------------------------------------------------

bool MemoryModule::Initialize() {
	if (m_initialized) {
		return true;
	}

	m_state = EngineState::Initializing;

	// -------------------------------------------------------------------------
	// TODO(v0.6)
	// Initialize memory services if needed.
	// -------------------------------------------------------------------------

	m_initialized = true;

	m_state = EngineState::Running;

	return true;
}

// -----------------------------------------------------------------------------

void MemoryModule::Update() {
	// -------------------------------------------------------------------------
	// Reserved for future diagnostics and memory monitoring.
	// -------------------------------------------------------------------------
}

// -----------------------------------------------------------------------------

void MemoryModule::Shutdown() {
	if (!m_initialized) {
		return;
	}

	m_state = EngineState::ShuttingDown;

	m_memoryManager.Reset();

	m_initialized = false;

	m_state = EngineState::Stopped;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

std::string_view MemoryModule::GetName() const {
	return "Memory";
}

// -----------------------------------------------------------------------------

std::string_view MemoryModule::GetVersion() const {
	return "0.6.0";
}

// -----------------------------------------------------------------------------

EngineState MemoryModule::GetState() const {
	return m_state;
}

// -----------------------------------------------------------------------------

bool MemoryModule::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------
// Memory
// -----------------------------------------------------------------------------

MemoryManager &MemoryModule::GetMemoryManager() {
	return m_memoryManager;
}

// -----------------------------------------------------------------------------

const MemoryManager &MemoryModule::GetMemoryManager() const {
	return m_memoryManager;
}
