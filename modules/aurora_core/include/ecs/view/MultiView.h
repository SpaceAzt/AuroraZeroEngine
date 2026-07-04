#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MultiView.h
 *
 * Description:
 *      ECS View for iterating entities that own multiple components.
 ******************************************************************************/

#include "ecs/storage/ComponentStorage.h"

#include <tuple>
#include <vector>

template <typename... Components>
class MultiView {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	MultiView() = default;

	explicit MultiView(
			ComponentStorage<Components> *...storages) :
			m_storages(storages...) {
		CollectEntities();
	}

	~MultiView() = default;

	// -------------------------------------------------------------------------
	// Utilities
	// -------------------------------------------------------------------------

	void CollectEntities();

	// -------------------------------------------------------------------------
	// Iterators
	// -------------------------------------------------------------------------

	auto begin() const {
		return m_entities.begin();
	}

	auto end() const {
		return m_entities.end();
	}

private:

    // -------------------------------------------------------------------------
	// TODO(v0.3.7)
	//
	// - Add iterator support.
	// - Add begin()/end().
	// - Optimize entity filtering.
	// -------------------------------------------------------------------------

	// -------------------------------------------------------------------------
	// Storage
	// -------------------------------------------------------------------------

	std::tuple<ComponentStorage<Components> *...> m_storages;

	

	// -------------------------------------------------------------------------
	// Filtered entities
	// -------------------------------------------------------------------------

	std::vector<EntityID> m_entities;

	// -------------------------------------------------------------------------
	// Helpers
	// -------------------------------------------------------------------------

	bool HasAllComponents(EntityID entity) const;

};

// -----------------------------------------------------------------------------
// HasAllComponents
// -----------------------------------------------------------------------------

template <typename... Components>
bool MultiView<Components...>::HasAllComponents(
		EntityID entity) const {
	return std::apply(
			[&](auto *...storages) {
				return (... && storages->Has(entity));
			},
			m_storages);
}

// -----------------------------------------------------------------------------
// CollectEntities
// -----------------------------------------------------------------------------

template <typename... Components>
void MultiView<Components...>::CollectEntities() {
	m_entities.clear();

	// İlk storage'ı al
	auto* firstStorage =
			std::get<0>(m_storages);

	// İlk storage'daki tüm entity'leri dolaş
	for (EntityID entity :
			firstStorage->GetSparseSet().GetDense()) {
		if (HasAllComponents(entity)) {
			m_entities.push_back(entity);
		}
	}
}
