/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      TimeManager.cpp
 *
 * Description:
 *      Central time management implementation.
 ******************************************************************************/

#include "TimeManager.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

TimeManager::TimeManager() = default;

TimeManager::~TimeManager() = default;

// -----------------------------------------------------------------------------
// Lifecycle
// -----------------------------------------------------------------------------

void TimeManager::Initialize() {
	m_snapshot = {};

	m_initialized = true;
}

// -----------------------------------------------------------------------------

void TimeManager::Shutdown() {
	m_initialized = false;
}

// -----------------------------------------------------------------------------

void TimeManager::Reset() {
	m_snapshot = {};
}

// -----------------------------------------------------------------------------

void TimeManager::Update(
		TimeSeconds deltaTime) {
	if (!m_initialized) {
		return;
	}

	m_snapshot.deltaTime = deltaTime;

	m_snapshot.totalTime += deltaTime;

	++m_snapshot.frameIndex;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

bool TimeManager::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

const TimeSnapshot &
TimeManager::GetSnapshot() const {
	return m_snapshot;
}

// -----------------------------------------------------------------------------

TimeSeconds TimeManager::GetDeltaTime() const {
	return m_snapshot.deltaTime;
}

// -----------------------------------------------------------------------------

TimeSeconds TimeManager::GetTotalTime() const {
	return m_snapshot.totalTime;
}

// -----------------------------------------------------------------------------

FrameIndex TimeManager::GetFrameIndex() const {
	return m_snapshot.frameIndex;
}
