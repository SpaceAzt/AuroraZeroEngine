#pragma once

#include <cstdint>

class Entity {
public:
	using Id = std::uint32_t;

	Entity();
	explicit Entity(Id id);

	Id GetId() const;

	bool IsValid() const;

	bool operator==(const Entity &other) const;
	bool operator!=(const Entity &other) const;

private:
	Id m_id = 0;
};
