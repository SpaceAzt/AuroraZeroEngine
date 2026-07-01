#include "../include/AuroraConfig.h"
#include "../include/AuroraLogger.h"

std::unordered_map<
		std::string,
		std::unordered_map<std::string, std::string>>
		AuroraConfig::m_config;

bool AuroraConfig::Load(const std::string &path) {
	AuroraLogger::Info("Loading Config : " + path);

	return true;
}

std::string AuroraConfig::GetString(
		const std::string &section,
		const std::string &key) {
	auto sec = m_config.find(section);

	if (sec == m_config.end()) {
		return "";
	}

	auto value = sec->second.find(key);

	if (value == sec->second.end()) {
		return "";
	}

	return value->second;
}
