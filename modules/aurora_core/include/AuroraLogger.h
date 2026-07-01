#pragma once

#include <string>

class AuroraLogger {
public:
	static void Info(const std::string &message);

	static void Warning(const std::string &message);

	static void Error(const std::string &message);

	static void Success(const std::string &message);
};
