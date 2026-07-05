#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ComponentManager.h
 *
 * Description:
 *      Manages all ECS component storages.
 ******************************************************************************/

#include "ecs/storage/IComponentStorage.h"
#include "ecs/storage/ComponentStorage.h"

#include <memory>
#include <typeindex>
#include <unordered_map>

class ComponentManager {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	ComponentManager();

	~ComponentManager();

	// -------------------------------------------------------------------------
	// Storage Management
	// -------------------------------------------------------------------------

	template <typename Component>
	void RegisterStorage();

	template <typename Component>
	[[nodiscard]]
	bool HasStorage() const;

    template <typename Component>
	[[nodiscard]]
	ComponentStorage<Component> *GetStorage();

	template <typename Component>
	[[nodiscard]]
	const ComponentStorage<Component> *GetStorage() const;

	// -------------------------------------------------------------------------
	// Entity Management
	// -------------------------------------------------------------------------

	void RemoveEntity(EntityID entity);

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	std::size_t StorageCount() const;

private:
	// -------------------------------------------------------------------------
	// Component Storages
	// -------------------------------------------------------------------------

	std::unordered_map<
			std::type_index,
			std::unique_ptr<IComponentStorage>>
			m_componentStorages;
};

// -----------------------------------------------------------------------------
// Register Storage
// -----------------------------------------------------------------------------

template <typename Component>
void ComponentManager::RegisterStorage() {
	if (HasStorage<Component>()) {
		return;
	}

	m_componentStorages.emplace(
			std::type_index(typeid(Component)),
			std::make_unique<ComponentStorage<Component>>());
}

// -----------------------------------------------------------------------------
// Has Storage
// -----------------------------------------------------------------------------

template <typename Component>
bool ComponentManager::HasStorage() const {
	return m_componentStorages.find(
				   std::type_index(typeid(Component))) != m_componentStorages.end();
}

// -----------------------------------------------------------------------------
// Get Storage
// -----------------------------------------------------------------------------

template <typename Component>
ComponentStorage<Component> *ComponentManager::GetStorage() {
	auto it = m_componentStorages.find(
			std::type_index(typeid(Component)));

	if (it == m_componentStorages.end()) {
		return nullptr;
	}

	return static_cast<ComponentStorage<Component> *>(
			it->second.get());
}

// -----------------------------------------------------------------------------
// Get Storage (const)
// -----------------------------------------------------------------------------

template <typename Component>
const ComponentStorage<Component> *ComponentManager::GetStorage() const {
	auto it = m_componentStorages.find(
			std::type_index(typeid(Component)));

	if (it == m_componentStorages.end()) {
		return nullptr;
	}

	return static_cast<const ComponentStorage<Component> *>(
			it->second.get());
}
