#include "../include/ecs/Entity.h"

Entity::Entity() = default;

Entity::Entity(Id id) :
		m_id(id) {
}

Entity::Id Entity::GetId() const {
	return m_id;
}

bool Entity::IsValid() const {
	return m_id != 0;
}

bool Entity::operator==(const Entity &other) const {
	return m_id == other.m_id;
}

bool Entity::operator!=(const Entity &other) const {
	return !(*this == other);
}
