#include "../include/AuroraFileSystem.h"
#include "../include/AuroraPlatform.h"
#include "../include/IFileProvider.h"

#include <filesystem>

bool AuroraFileSystem::Exists(const std::string &path) {
	auto *provider = AuroraPlatform::GetFileProvider();

	if (!provider) {
		return false;
	}

	return provider->Exists(path);
}

bool AuroraFileSystem::CreateDirectory(const std::string &path) {
	auto *provider = AuroraPlatform::GetFileProvider();

	if (!provider) {
		return false;
	}

	return provider->CreateDirectory(path);
}

bool AuroraFileSystem::Remove(const std::string &path) {
	auto *provider = AuroraPlatform::GetFileProvider();

	if (!provider) {
		return false;
	}

	return provider->Remove(path);
}
