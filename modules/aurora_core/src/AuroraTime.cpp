#include "../include/AuroraTime.h"

#include <GLFW/glfw3.h>

float AuroraTime::m_deltaTime = 0.0f;

double AuroraTime::m_totalTime = 0.0;

void AuroraTime::Initialize() {
	m_totalTime = glfwGetTime();
}

void AuroraTime::Update() {
	double currentTime = glfwGetTime();

	m_deltaTime = static_cast<float>(currentTime - m_totalTime);

	m_totalTime = currentTime;
}

float AuroraTime::GetDeltaTime() {
	return m_deltaTime;
}

double AuroraTime::GetTotalTime() {
	return m_totalTime;
}
