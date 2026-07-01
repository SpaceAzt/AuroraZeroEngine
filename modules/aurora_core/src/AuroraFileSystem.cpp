#include "../include/AuroraFileSystem.h"

#include <filesystem>

bool AuroraFileSystem::Exists(const std::string &path) {
	return std::filesystem::exists(path);
}

bool AuroraFileSystem::CreateDirectory(const std::string &path) {
	return std::filesystem::create_directories(path);
}

bool AuroraFileSystem::Remove(const std::string &path) {
	return std::filesystem::remove(path);
}
