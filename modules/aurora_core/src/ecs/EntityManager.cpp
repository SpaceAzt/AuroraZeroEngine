#include "../include/ecs/EntityManager.h"

EntityManager::EntityManager(Registry &registry) :
		m_registry(registry) {
}

Entity EntityManager::Create() {
	return m_registry.CreateEntity();
}

void EntityManager::Destroy(Entity entity) {
	m_registry.DestroyEntity(entity);
}
