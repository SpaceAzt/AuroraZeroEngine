#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ComponentStorage.h
 *
 * Description:
 *      Generic storage for a single component type.
 ******************************************************************************/

#include "ecs/storage/IComponentStorage.h"
#include "ecs/storage/SparseSet.h"

#include <utility>
#include <vector>

template <typename T>
class ComponentStorage : public IComponentStorage {
public:
	ComponentStorage() = default;

	~ComponentStorage() override = default;

	void RemoveEntity(EntityID entity) override {
		Remove(entity);
	}

	void Clear() override {
		m_sparseSet.Clear();
		m_components.clear();
	}

	void Add(EntityID entity, const T &component);

	void Remove(EntityID entity);

	bool Has(EntityID entity) const;

	T &Get(EntityID entity);

	const T &Get(EntityID entity) const;

private:
	// -------------------------------------------------------------------------
	// TODO(v0.4):
	// Replace SparseSet with a templated SparseSet<ComponentType>
	// to eliminate duplicated dense storage.
	// -------------------------------------------------------------------------

	SparseSet m_sparseSet;

	std::vector<T> m_components;
};

// -----------------------------------------------------------------------------
// Add
// -----------------------------------------------------------------------------

template <typename T>
void ComponentStorage<T>::Add(EntityID entity, const T &component) {
	if (Has(entity)) {
		return;
	}

	m_sparseSet.Insert(entity);
	m_components.push_back(component);
}

// -----------------------------------------------------------------------------
// Remove
// -----------------------------------------------------------------------------

template <typename T>
void ComponentStorage<T>::Remove(EntityID entity) {
	if (!Has(entity)) {
		return;
	}

	const size_t index = m_sparseSet.GetDenseIndex(entity);
	const size_t last = m_components.size() - 1;

	if (index != last) {
		m_components[index] = std::move(m_components[last]);
	}

	m_components.pop_back();

	m_sparseSet.Remove(entity);
}

// -----------------------------------------------------------------------------
// Has
// -----------------------------------------------------------------------------

template <typename T>
bool ComponentStorage<T>::Has(EntityID entity) const {
	return m_sparseSet.Contains(entity);
}

// -----------------------------------------------------------------------------
// Get
// -----------------------------------------------------------------------------

template <typename T>
T &ComponentStorage<T>::Get(EntityID entity) {
	return m_components[m_sparseSet.GetDenseIndex(entity)];
}

// -----------------------------------------------------------------------------
// Get (const)
// -----------------------------------------------------------------------------

template <typename T>
const T &ComponentStorage<T>::Get(EntityID entity) const {
	return m_components[m_sparseSet.GetDenseIndex(entity)];
}
