/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      Registry.cpp
 *
 * Description:
 *      ECS entity registry implementation.
 ******************************************************************************/

#include "ecs/Registry.h"

#include <algorithm>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

Registry::Registry() = default;

// -----------------------------------------------------------------------------
// CreateEntity
// -----------------------------------------------------------------------------

Entity Registry::CreateEntity() {
	Entity entity(m_nextEntityId++);

	m_entities.emplace_back(entity);

	return entity;
}

// -----------------------------------------------------------------------------
// DestroyEntity
// -----------------------------------------------------------------------------

void Registry::DestroyEntity(Entity entity) {
	// -------------------------------------------------------------------------
	// TODO(v0.4)
	// Remove all components owned by this entity.
	// -------------------------------------------------------------------------

	auto it = std::remove(
			m_entities.begin(),
			m_entities.end(),
			entity);

	m_entities.erase(
			it,
			m_entities.end());
}

// -----------------------------------------------------------------------------
// IsAlive
// -----------------------------------------------------------------------------

bool Registry::IsAlive(Entity entity) const {
	return std::find(
				   m_entities.begin(),
				   m_entities.end(),
				   entity) != m_entities.end();
}
