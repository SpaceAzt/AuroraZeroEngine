#pragma once

class ITimeProvider {
public:
	virtual ~ITimeProvider() = default;

	virtual void Initialize() = 0;

	virtual void Update() = 0;

	virtual float GetDeltaTime() const = 0;

	virtual double GetTotalTime() const = 0;
};
