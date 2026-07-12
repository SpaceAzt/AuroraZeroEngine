/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      TimeModule.cpp
 *
 * Description:
 *      Time system module implementation.
 ******************************************************************************/

#include "TimeModule.h"

TimeModule::TimeModule() = default;

TimeModule::~TimeModule() = default;

// -----------------------------------------------------------------------------

bool TimeModule::Initialize() {
	if (m_initialized) {
		return true;
	}

	m_timeManager.Initialize();

	m_initialized = true;

	m_state = EngineState::Running;

	return true;
}

// -----------------------------------------------------------------------------

void TimeModule::Update() {
	if (!m_initialized) {
		return;
	}

	// TODO:
	// Delta time will come from ITimeProvider.

	m_timeManager.Update(0.0);
}

// -----------------------------------------------------------------------------

void TimeModule::Shutdown() {
	if (!m_initialized) {
		return;
	}

	m_timeManager.Shutdown();

	m_initialized = false;

	m_state = EngineState::Stopped;
}

// -----------------------------------------------------------------------------

std::string_view TimeModule::GetName() const {
	return "Time";
}

// -----------------------------------------------------------------------------

std::string_view TimeModule::GetVersion() const {
	return "1.0.0";
}

// -----------------------------------------------------------------------------

bool TimeModule::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

EngineState TimeModule::GetState() const {
	return m_state;
}

// -----------------------------------------------------------------------------

TimeManager &
TimeModule::GetTimeManager() {
	return m_timeManager;
}

// -----------------------------------------------------------------------------

const TimeManager &
TimeModule::GetTimeManager() const {
	return m_timeManager;
}
