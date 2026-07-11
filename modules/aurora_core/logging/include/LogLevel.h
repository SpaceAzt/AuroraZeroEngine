#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LogLevel.h
 *
 * Description:
 *      Defines log severity levels.
 ******************************************************************************/

enum class LogLevel {
	Trace,

	Debug,

	Info,

	Warning,

	Error,

	Critical
};

// -----------------------------------------------------------------------------
// Utilities
// -----------------------------------------------------------------------------

[[nodiscard]]
const char *ToString(
		LogLevel level);
