#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      TimeModule.h
 *
 * Description:
 *      Time system module.
 ******************************************************************************/

#include "IModule.h"
#include "TimeManager.h"

class TimeModule final : public IModule {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	TimeModule();

	~TimeModule() override;

	// -------------------------------------------------------------------------
	// IModule
	// -------------------------------------------------------------------------

	bool Initialize() override;

	void Update() override;

	void Shutdown() override;

	[[nodiscard]]
	std::string_view GetName() const override;

	[[nodiscard]]
	std::string_view GetVersion() const override;

	[[nodiscard]]
	bool IsInitialized() const override;

	[[nodiscard]]
	EngineState GetState() const override;

	// -------------------------------------------------------------------------
	// Access
	// -------------------------------------------------------------------------

	[[nodiscard]]
	TimeManager &GetTimeManager();

	[[nodiscard]]
	const TimeManager &GetTimeManager() const;

private:
	TimeManager m_timeManager;

	bool m_initialized = false;

	EngineState m_state = EngineState::Created;
};
