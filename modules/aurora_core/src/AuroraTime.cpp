#include "../include/AuroraTime.h"
#include "../include/AuroraPlatform.h"
#include "../include/ITimeProvider.h"

float AuroraTime::m_deltaTime = 0.0f;
double AuroraTime::m_totalTime = 0.0;

void AuroraTime::Initialize() {
	auto *provider = AuroraPlatform::GetTimeProvider();

	if (provider) {
		provider->Initialize();
	}
}

void AuroraTime::Update() {
	auto *provider = AuroraPlatform::GetTimeProvider();

	if (provider) {
		provider->Update();
	}
}

float AuroraTime::GetDeltaTime() {
	auto *provider = AuroraPlatform::GetTimeProvider();

	if (provider) {
		return provider->GetDeltaTime();
	}

	return 0.0f;
}

double AuroraTime::GetTotalTime() {
	auto *provider = AuroraPlatform::GetTimeProvider();

	if (provider) {
		return provider->GetTotalTime();
	}

	return 0.0;
}
