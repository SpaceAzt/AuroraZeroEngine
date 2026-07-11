#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LogManager.h
 *
 * Description:
 *      Central logging manager.
 ******************************************************************************/

#include "ILogger.h"
#include "LogMessage.h"

#include <vector>

class LogManager {
public:
	// -------------------------------------------------------------------------
	// Singleton
	// -------------------------------------------------------------------------

	static LogManager &Get();

	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	LogManager();

	~LogManager();

	LogManager(const LogManager &) = delete;
	LogManager &operator=(const LogManager &) = delete;

	// -------------------------------------------------------------------------
	// Logger Management
	// -------------------------------------------------------------------------

	bool RegisterLogger(
			ILogger *logger);

	bool UnregisterLogger(
			ILogger *logger);

	void Clear();

	// -------------------------------------------------------------------------
	// Logging
	// -------------------------------------------------------------------------

	void Log(
			const LogMessage &message);

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	std::size_t GetLoggerCount() const;

	[[nodiscard]]
	const std::vector<ILogger *> &GetLoggers() const;

	[[nodiscard]]
	bool IsRegistered(
			const ILogger *logger) const;

private:
	std::vector<ILogger *> m_loggers;
};

