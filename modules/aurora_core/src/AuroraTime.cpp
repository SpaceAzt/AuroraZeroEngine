#include "../include/AuroraTime.h"

float AuroraTime::m_deltaTime = 0.0f;
double AuroraTime::m_totalTime = 0.0;

void AuroraTime::Initialize() {
	m_deltaTime = 0.0f;
	m_totalTime = 0.0;
}

void AuroraTime::Update() {
	// Şimdilik boş.
	// Gerçek zaman bilgisi GodotTimeProvider üzerinden gelecek.
}

float AuroraTime::GetDeltaTime() {
	return m_deltaTime;
}

double AuroraTime::GetTotalTime() {
	return m_totalTime;
}
