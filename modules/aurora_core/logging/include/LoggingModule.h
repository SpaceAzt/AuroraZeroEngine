#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LoggingModule.h
 *
 * Description:
 *      Logging system module.
 ******************************************************************************/

#include "IModule.h"
#include <memory>

class ConsoleLogger;

class LoggingModule final : public IModule {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	LoggingModule();

	~LoggingModule() override;

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

private:
	std::unique_ptr<ConsoleLogger> m_consoleLogger;

	bool m_initialized = false;

	EngineState m_state = EngineState::Created;
};
