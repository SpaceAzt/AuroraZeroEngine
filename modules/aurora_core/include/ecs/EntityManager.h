#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EntityManager.h
 *
 * Description:
 *      High-level interface for entity management.
 ******************************************************************************/

#include "Registry.h"

class EntityManager {
public:
	explicit EntityManager(Registry &registry);

	Entity Create();

	void Destroy(Entity entity);

private:

	// -------------------------------------------------------------------------
	// TODO(v0.5):
	// Extend EntityManager with higher-level entity features.
	//
	// Planned features:
	// - Entity names
	// - Entity tags
	// - Prefab support
	// - Scene ownership
	// -------------------------------------------------------------------------

	Registry &m_registry;
};
