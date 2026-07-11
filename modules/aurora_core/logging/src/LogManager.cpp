/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LogManager.cpp
 *
 * Description:
 *      Central logging manager implementation.
 ******************************************************************************/

#include "LogManager.h"

#include <algorithm>

// -----------------------------------------------------------------------------
// Singleton
// -----------------------------------------------------------------------------

LogManager &LogManager::Get() {
	static LogManager instance;

	return instance;
}

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

LogManager::LogManager() = default;

LogManager::~LogManager() = default;

// -----------------------------------------------------------------------------
// Logger Management
// -----------------------------------------------------------------------------

bool LogManager::RegisterLogger(
		ILogger *logger) {
	if (logger == nullptr) {
		return false;
	}

	auto it = std::find(
			m_loggers.begin(),
			m_loggers.end(),
			logger);

	if (it != m_loggers.end()) {
		return false;
	}

	m_loggers.push_back(logger);

	return true;
}

// -----------------------------------------------------------------------------

bool LogManager::UnregisterLogger(
		ILogger *logger) {
	auto it = std::find(
			m_loggers.begin(),
			m_loggers.end(),
			logger);

	if (it == m_loggers.end()) {
		return false;
	}

	m_loggers.erase(it);

	return true;
}

// -----------------------------------------------------------------------------

bool LogManager::IsRegistered(
		const ILogger *logger) const {
	return std::find(
				   m_loggers.begin(),
				   m_loggers.end(),
				   logger) != m_loggers.end();
}

// -----------------------------------------------------------------------------

void LogManager::Clear() {
	m_loggers.clear();
}

// -----------------------------------------------------------------------------
// Logging
// -----------------------------------------------------------------------------

void LogManager::Log(
		const LogMessage &message) {
	for (ILogger *logger : m_loggers) {
		if (logger == nullptr) {
			continue;
		}

		if (!logger->IsEnabled()) {
			continue;
		}

		logger->Log(message);
	}
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

std::size_t LogManager::GetLoggerCount() const {
	return m_loggers.size();
}

// -----------------------------------------------------------------------------

const std::vector<ILogger *> &
LogManager::GetLoggers() const {
	return m_loggers;
}
