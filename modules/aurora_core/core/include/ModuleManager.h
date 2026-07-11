#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ModuleManager.h
 *
 * Description:
 *      Manages all engine modules.
 ******************************************************************************/

#include "IModule.h"

#include <string_view>
#include <vector>

class ModuleManager {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	ModuleManager();

	~ModuleManager();

	// -------------------------------------------------------------------------
	// Module Management
	// -------------------------------------------------------------------------

	bool RegisterModule(IModule *module);

	bool UnregisterModule(IModule *module);

	[[nodiscard]]
	bool IsRegistered(
			const IModule *module) const;

	// -------------------------------------------------------------------------
	// Lifecycle
	// -------------------------------------------------------------------------

	void InitializeModules();

	void UpdateModules();

	void ShutdownModules();

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	IModule *FindModule(
			std::string_view name);

	[[nodiscard]]
	const IModule *FindModule(
			std::string_view name) const;

	[[nodiscard]]
	std::size_t GetModuleCount() const;

	[[nodiscard]]
	const std::vector<IModule *> &GetModules() const;

private:
	std::vector<IModule *> m_modules;
};
