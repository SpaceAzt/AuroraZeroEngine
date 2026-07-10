#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      IModule.h
 *
 * Description:
 *      Base interface for all Aurora engine modules.
 ******************************************************************************/

#include "EngineState.h"

#include <string_view>

class IModule {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	virtual ~IModule() = default;

	// -------------------------------------------------------------------------
	// Lifecycle
	// -------------------------------------------------------------------------

	virtual bool Initialize() = 0;

	virtual void Update() = 0;

	virtual void Shutdown() = 0;

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	virtual std::string_view GetName() const = 0;

	[[nodiscard]]
	virtual std::string_view GetVersion() const = 0;

	[[nodiscard]]
	virtual bool IsInitialized() const = 0;

	[[nodiscard]]
	virtual EngineState GetState() const = 0;
};
