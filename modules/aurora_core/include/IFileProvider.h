#pragma once

#include <string>

class IFileProvider {
public:
	virtual ~IFileProvider() = default;

	virtual bool Exists(const std::string &path) = 0;

	virtual bool CreateDirectory(const std::string &path) = 0;

	virtual bool Remove(const std::string &path) = 0;
};
