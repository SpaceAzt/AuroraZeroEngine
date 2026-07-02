#include "../include/GodotFileProvider.h"
#include <filesystem>

bool GodotFileProvider::Exists(const std::string &path) {
	return std::filesystem::exists(path);
}

bool GodotFileProvider::CreateDirectory(const std::string &path) {
	return std::filesystem::create_directories(path);
}

bool GodotFileProvider::Remove(const std::string &path) {
	return std::filesystem::remove(path);
}
