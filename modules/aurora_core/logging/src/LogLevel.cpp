/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LogLevel.cpp
 *
 * Description:
 *      Log level utilities.
 ******************************************************************************/

#include "LogLevel.h"

const char *ToString(
		LogLevel level) {
	switch (level) {
		case LogLevel::Trace:
			return "TRACE";

		case LogLevel::Debug:
			return "DEBUG";

		case LogLevel::Info:
			return "INFO";

		case LogLevel::Warning:
			return "WARNING";

		case LogLevel::Error:
			return "ERROR";

		case LogLevel::Critical:
			return "CRITICAL";

		default:
			return "UNKNOWN";
	}
}
