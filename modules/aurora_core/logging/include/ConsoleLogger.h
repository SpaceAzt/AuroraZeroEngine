#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ConsoleLogger.h
 *
 * Description:
 *      Console logger implementation.
 ******************************************************************************/

#include "ILogger.h"

class ConsoleLogger final : public ILogger {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	ConsoleLogger();

	~ConsoleLogger() override;

	// -------------------------------------------------------------------------
	// ILogger
	// -------------------------------------------------------------------------

	void Log(
			const LogMessage &message) override;

	[[nodiscard]]
	bool IsEnabled() const override;

	void SetEnabled(
			bool enabled) override;

private:
	bool m_enabled = true;
};
