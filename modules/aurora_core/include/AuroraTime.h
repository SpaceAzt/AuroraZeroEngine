#pragma once

class AuroraTime {
public:
	static void Initialize();

	static void Update();

	static float GetDeltaTime();

	static double GetTotalTime();

private:
	static float m_deltaTime;

	static double m_totalTime;
};
