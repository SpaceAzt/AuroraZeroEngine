#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      Registry.h
 *
 * Description:
 *      Central ECS registry.
 *      Responsible for entity creation and lifetime.
 ******************************************************************************/

#include "Entity.h"

#include <vector>

class Registry {
public:
	Registry();

	Entity CreateEntity();

	void DestroyEntity(Entity entity);

	bool IsAlive(Entity entity) const;


private:

	 // -------------------------------------------------------------------------
	// TODO(v0.4):
	// Add component storage and lookup.
	// Planned:
	// - Component pools
	// - Fast component queries
	// - Sparse set storage
	// -------------------------------------------------------------------------

	Entity::Id m_nextEntityId = 1;

	std::vector<Entity> m_entities;
};
