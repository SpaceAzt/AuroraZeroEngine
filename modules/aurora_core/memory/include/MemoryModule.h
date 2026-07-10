#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MemoryModule.h
 *
 * Description:
 *      Aurora memory engine module.
 ******************************************************************************/

#include "MemoryManager.h"

#include "EngineState.h"
#include "IModule.h"

#include <string_view>

class MemoryModule final : public IModule {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	MemoryModule();

	~MemoryModule() override;

	// -------------------------------------------------------------------------
	// Lifecycle
	// -------------------------------------------------------------------------

	bool Initialize() override;

	void Update() override;

	void Shutdown() override;

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	std::string_view GetName() const override;

	[[nodiscard]]
	std::string_view GetVersion() const override;

	[[nodiscard]]
	EngineState GetState() const override;

	[[nodiscard]]
	bool IsInitialized() const override;

	// -------------------------------------------------------------------------
	// Memory
	// -------------------------------------------------------------------------

	[[nodiscard]]
	MemoryManager &GetMemoryManager();

	[[nodiscard]]
	const MemoryManager &GetMemoryManager() const;

private:
	MemoryManager m_memoryManager;

	EngineState m_state = EngineState::Created;

	bool m_initialized = false;
};
