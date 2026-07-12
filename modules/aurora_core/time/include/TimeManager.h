#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      TimeManager.h
 *
 * Description:
 *      Central time management system.
 ******************************************************************************/

#include "TimeSnapshot.h"

class TimeManager {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	TimeManager();

	~TimeManager();

	// -------------------------------------------------------------------------
	// Lifecycle
	// -------------------------------------------------------------------------

	void Initialize();

	void Shutdown();

	void Reset();

	void Update(
			TimeSeconds deltaTime);

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	bool IsInitialized() const;

	[[nodiscard]]
	const TimeSnapshot &GetSnapshot() const;

	[[nodiscard]]
	TimeSeconds GetDeltaTime() const;

	[[nodiscard]]
	TimeSeconds GetTotalTime() const;

	[[nodiscard]]
	FrameIndex GetFrameIndex() const;

private:
	TimeSnapshot m_snapshot;

	bool m_initialized = false;
};
