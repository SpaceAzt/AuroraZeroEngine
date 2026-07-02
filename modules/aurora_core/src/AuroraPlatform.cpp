#include "../include/AuroraLogger.h"
#include "../include/AuroraPlatform.h"
#include "../include/ITimeProvider.h"
#include "../include/IFileProvider.h"

ITimeProvider *AuroraPlatform::s_timeProvider = nullptr;
IFileProvider *AuroraPlatform::s_fileProvider = nullptr;


void AuroraPlatform::Initialize() {

	AuroraLogger::Success("Aurora Platform Initialized");
}

void AuroraPlatform::Shutdown() {
	AuroraLogger::Info("Aurora Platform Shutdown");
	s_timeProvider = nullptr;
	s_fileProvider = nullptr;
}

void AuroraPlatform::SetTimeProvider(ITimeProvider *provider) {
	s_timeProvider = provider;
}

ITimeProvider *AuroraPlatform::GetTimeProvider() {
	return s_timeProvider;
}

void AuroraPlatform::SetFileProvider(IFileProvider *provider) {
	s_fileProvider = provider;
}

IFileProvider *AuroraPlatform::GetFileProvider() {
	return s_fileProvider;
}
