#pragma once

#include "IFileProvider.h"

class GodotFileProvider : public IFileProvider {
public:
	bool Exists(const std::string &path) override;

	bool CreateDirectory(const std::string &path) override;

	bool Remove(const std::string &path) override;
};
