#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      PlatformModule.h
 *
 * Description:
 *      Platform system module.
 ******************************************************************************/

#include "IModule.h"
#include "PlatformManager.h"

#include <memory>

class GodotTimeProvider;
class GodotFileProvider;

class PlatformModule final : public IModule {
public:
	PlatformModule();

	~PlatformModule() override;

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

	[[nodiscard]]
	PlatformManager &GetPlatformManager();

	[[nodiscard]]
	const PlatformManager &GetPlatformManager() const;

private:
	PlatformManager m_platformManager;

	std::unique_ptr<GodotTimeProvider> m_timeProvider;

	std::unique_ptr<GodotFileProvider> m_fileProvider;

	bool m_initialized = false;

	EngineState m_state = EngineState::Created;
};
