/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ModuleManager.cpp
 *
 * Description:
 *      Engine module manager implementation.
 ******************************************************************************/

#include "ModuleManager.h"

#include "AuroraLogger.h"

#include <algorithm>
#include <string>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

ModuleManager::ModuleManager() = default;

// -----------------------------------------------------------------------------

ModuleManager::~ModuleManager() = default;

// -----------------------------------------------------------------------------
// Module Management
// -----------------------------------------------------------------------------

bool ModuleManager::RegisterModule(
		IModule *module) {
	if (module == nullptr) {
		return false;
	}

	if (IsRegistered(module)) {
		return false;
	}

	m_modules.push_back(module);

	AuroraLogger::Info(
			"Registered module: " +
			std::string(module->GetName()));

	return true;
}

// -----------------------------------------------------------------------------

bool ModuleManager::UnregisterModule(
		IModule *module) {
	auto it = std::find(
			m_modules.begin(),
			m_modules.end(),
			module);

	if (it == m_modules.end()) {
		return false;
	}

	AuroraLogger::Info(
			"Unregistered module: " +
			std::string(module->GetName()));

	m_modules.erase(it);

	return true;
}

// -----------------------------------------------------------------------------

bool ModuleManager::IsRegistered(
		const IModule *module) const {
	return std::find(
				   m_modules.begin(),
				   m_modules.end(),
				   module) != m_modules.end();
}

// -----------------------------------------------------------------------------
// Lifecycle
// -----------------------------------------------------------------------------

void ModuleManager::InitializeModules() {
	for (IModule *module : m_modules) {
		if (module == nullptr) {
			continue;
		}

		if (!module->Initialize()) {
			AuroraLogger::Error(
					"Failed to initialize module: " +
					std::string(module->GetName()));

			continue;
		}

		AuroraLogger::Success(
				"Initialized module: " +
				std::string(module->GetName()));
	}
}

// -----------------------------------------------------------------------------

void ModuleManager::UpdateModules() {
	for (IModule *module : m_modules) {
		if (module == nullptr) {
			continue;
		}

		if (!module->IsInitialized()) {
			continue;
		}

		module->Update();
	}
}

// -----------------------------------------------------------------------------

void ModuleManager::ShutdownModules() {
	for (auto it = m_modules.rbegin();
			it != m_modules.rend();
			++it) {
		IModule *module = *it;

		if (module == nullptr) {
			continue;
		}

		if (!module->IsInitialized()) {
			continue;
		}

		module->Shutdown();

		AuroraLogger::Info(
				"Shutdown module: " +
				std::string(module->GetName()));
	}
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

IModule *ModuleManager::FindModule(
		std::string_view name) {
	for (IModule *module : m_modules) {
		if (module != nullptr &&
				module->GetName() == name) {
			return module;
		}
	}

	return nullptr;
}

// -----------------------------------------------------------------------------

const IModule *ModuleManager::FindModule(
		std::string_view name) const {
	for (const IModule *module : m_modules) {
		if (module != nullptr &&
				module->GetName() == name) {
			return module;
		}
	}

	return nullptr;
}

// -----------------------------------------------------------------------------

std::size_t ModuleManager::GetModuleCount() const {
	return m_modules.size();
}

// -----------------------------------------------------------------------------

const std::vector<IModule *> &
ModuleManager::GetModules() const {
	return m_modules;
}
