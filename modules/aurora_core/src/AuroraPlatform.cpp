#include "../include/AuroraPlatform.h"

#include "../include/ITimeProvider.h"

ITimeProvider *AuroraPlatform::s_timeProvider = nullptr;

void AuroraPlatform::Initialize() {
}

void AuroraPlatform::Shutdown() {
	s_timeProvider = nullptr;
}

void AuroraPlatform::SetTimeProvider(ITimeProvider *provider) {
	s_timeProvider = provider;
}

ITimeProvider *AuroraPlatform::GetTimeProvider() {
	return s_timeProvider;
}
