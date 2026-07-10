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

#include <algorithm>

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

	auto it = std::find(
			m_modules.begin(),
			m_modules.end(),
			module);

	if (it != m_modules.end()) {
		return false;
	}

	m_modules.push_back(module);

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

	m_modules.erase(it);

	return true;
}

// -----------------------------------------------------------------------------
// Lifecycle
// -----------------------------------------------------------------------------

void ModuleManager::InitializeModules() {
	for (IModule *module : m_modules) {
		if (module != nullptr) {
			module->Initialize();
		}
	}
}

// -----------------------------------------------------------------------------

void ModuleManager::UpdateModules() {
	for (IModule *module : m_modules) {
		if (module != nullptr) {
			module->Update();
		}
	}
}

// -----------------------------------------------------------------------------

void ModuleManager::ShutdownModules() {
	for (auto it = m_modules.rbegin();
			it != m_modules.rend();
			++it) {
		if (*it != nullptr) {
			(*it)->Shutdown();
		}
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
