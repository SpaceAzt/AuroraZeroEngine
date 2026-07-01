#include "../include/GodotTimeProvider.h"

void GodotTimeProvider::Initialize() {
	m_deltaTime = 0.0f;
	m_totalTime = 0.0;
}

void GodotTimeProvider::Update() {
	// TODO:
	// Godot Engine zaman sistemi buraya bağlanacak.
}

float GodotTimeProvider::GetDeltaTime() const {
	return m_deltaTime;
}

double GodotTimeProvider::GetTotalTime() const {
	return m_totalTime;
}
