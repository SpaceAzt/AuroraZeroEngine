/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ComponentManager.cpp
 *
 * Description:
 *      Component manager implementation.
 ******************************************************************************/

#include "ecs/ComponentManager.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

ComponentManager::ComponentManager() = default;

ComponentManager::~ComponentManager() = default;

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

std::size_t ComponentManager::StorageCount() const {
	return m_componentStorages.size();
}

// -----------------------------------------------------------------------------
// Remove Entity
// -----------------------------------------------------------------------------

void ComponentManager::RemoveEntity(EntityID entity) {
	for (auto &storage : m_componentStorages) {
		storage.second->RemoveEntity(entity);
	}
}
