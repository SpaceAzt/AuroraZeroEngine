#pragma once

#include <string>
#include <unordered_map>

class AuroraConfig {
public:
	static bool Load(const std::string &path);

	static std::string GetString(const std::string &section,
			const std::string &key);

private:
	static std::unordered_map<
			std::string,
			std::unordered_map<std::string, std::string>>
			m_config;
};
