/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LoggingModule.cpp
 *
 * Description:
 *      Logging system module implementation.
 ******************************************************************************/

#include "LoggingModule.h"

#include "ConsoleLogger.h"
#include "LogManager.h"

#include <memory>

LoggingModule::LoggingModule() = default;

LoggingModule::~LoggingModule() = default;

// -----------------------------------------------------------------------------

bool LoggingModule::Initialize() {
	if (m_initialized) {
		return true;
	}

	m_consoleLogger = std::make_unique<ConsoleLogger>();

	LogManager::Get().RegisterLogger(
			m_consoleLogger.get());

	m_initialized = true;

	m_state = EngineState::Running;

	return true;
}

// -----------------------------------------------------------------------------

void LoggingModule::Update() {
	// Nothing to update.
}

// -----------------------------------------------------------------------------

void LoggingModule::Shutdown() {
	if (!m_initialized) {
		return;
	}

	LogManager::Get().UnregisterLogger(
			m_consoleLogger.get());

	m_consoleLogger.reset();

	m_consoleLogger = nullptr;

	m_initialized = false;

	m_state = EngineState::Stopped;
}

// -----------------------------------------------------------------------------

std::string_view LoggingModule::GetName() const {
	return "Logging";
}

// -----------------------------------------------------------------------------

std::string_view LoggingModule::GetVersion() const {
	return "1.0.0";
}

// -----------------------------------------------------------------------------

bool LoggingModule::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

EngineState LoggingModule::GetState() const {
	return m_state;
}
