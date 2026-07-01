#pragma once

#include <string>

class AuroraFileSystem {
public:
	static bool Exists(const std::string &path);

	static bool CreateDirectory(const std::string &path);

	static bool Remove(const std::string &path);
};
