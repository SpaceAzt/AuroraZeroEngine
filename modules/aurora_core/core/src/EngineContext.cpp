#include "EngineContext.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

EngineContext::EngineContext() = default;

// -----------------------------------------------------------------------------

EngineContext::~EngineContext() = default;

// -----------------------------------------------------------------------------
// Access
// -----------------------------------------------------------------------------

ModuleManager &
EngineContext::GetModuleManager() {
	return m_moduleManager;
}

// -----------------------------------------------------------------------------

const ModuleManager &
EngineContext::GetModuleManager() const {
	return m_moduleManager;
}

// -----------------------------------------------------------------------------
// State
// -----------------------------------------------------------------------------

EngineState
EngineContext::GetEngineState() const {
	return m_engineState;
}

// -----------------------------------------------------------------------------

void EngineContext::SetEngineState(
		EngineState state) {
	m_engineState = state;
}
