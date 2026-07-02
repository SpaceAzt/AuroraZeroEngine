#include "../include/ecs/Registry.h"

#include <algorithm>

Registry::Registry() = default;

Entity Registry::CreateEntity() {
	Entity entity(m_nextEntityId++);

	m_entities.push_back(entity);

	return entity;
}

void Registry::DestroyEntity(Entity entity) {
	m_entities.erase(

			std::remove(
					m_entities.begin(),
					m_entities.end(),
					entity),

			m_entities.end());
}

bool Registry::IsAlive(Entity entity) const {
	return std::find(
				   m_entities.begin(),
				   m_entities.end(),
				   entity)

			!= m_entities.end();
}
