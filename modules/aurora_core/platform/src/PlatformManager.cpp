/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      PlatformManager.cpp
 *
 * Description:
 *      Platform manager implementation.
 ******************************************************************************/

#include "PlatformManager.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

PlatformManager::PlatformManager() = default;

PlatformManager::~PlatformManager() = default;

// -----------------------------------------------------------------------------
// Lifecycle
// -----------------------------------------------------------------------------

void PlatformManager::Initialize() {
	m_initialized = true;
}

// -----------------------------------------------------------------------------

void PlatformManager::Shutdown() {
	m_timeProvider = nullptr;

	m_fileProvider = nullptr;

	m_initialized = false;
}

// -----------------------------------------------------------------------------
// Providers
// -----------------------------------------------------------------------------

void PlatformManager::SetTimeProvider(
		ITimeProvider *provider) {
	m_timeProvider = provider;
}

// -----------------------------------------------------------------------------

ITimeProvider *
PlatformManager::GetTimeProvider() const {
	return m_timeProvider;
}

// -----------------------------------------------------------------------------

void PlatformManager::SetFileProvider(
		IFileProvider *provider) {
	m_fileProvider = provider;
}

// -----------------------------------------------------------------------------

IFileProvider *
PlatformManager::GetFileProvider() const {
	return m_fileProvider;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

bool PlatformManager::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

const PlatformInfo &
PlatformManager::GetPlatformInfo() const {
	return m_platformInfo;
}
