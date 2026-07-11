/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ConsoleLogger.cpp
 *
 * Description:
 *      Console logger implementation.
 ******************************************************************************/

#include "ConsoleLogger.h"

#include <iostream>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

ConsoleLogger::ConsoleLogger() = default;

// -----------------------------------------------------------------------------

ConsoleLogger::~ConsoleLogger() = default;

// -----------------------------------------------------------------------------
// ILogger
// -----------------------------------------------------------------------------

void ConsoleLogger::Log(
		const LogMessage &message) {
	if (!m_enabled) {
		return;
	}

	std::cout
			<< '['
			<< ToString(message.level)
			<< "] ";

	if (!message.module.empty()) {
		std::cout
				<< '['
				<< message.module
				<< "] ";
	}

	std::cout
			<< message.message
			<< std::endl;
}

// -----------------------------------------------------------------------------

bool ConsoleLogger::IsEnabled() const {
	return m_enabled;
}

// -----------------------------------------------------------------------------

void ConsoleLogger::SetEnabled(
		bool enabled) {
	m_enabled = enabled;
}
