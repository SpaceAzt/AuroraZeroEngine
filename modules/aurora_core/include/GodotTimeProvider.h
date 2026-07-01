#pragma once

#include "ITimeProvider.h"

class GodotTimeProvider : public ITimeProvider {
public:
	void Initialize() override;

	void Update() override;

	float GetDeltaTime() const override;

	double GetTotalTime() const override;

private:
	float m_deltaTime = 0.0f;
	double m_totalTime = 0.0;
};
