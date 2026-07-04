#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      View.h
 *
 * Description:
 *      ECS View for iterating entities that own a specific component.
 ******************************************************************************/

#include "ecs/storage/ComponentStorage.h"

template <typename T>
class View {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	explicit View(ComponentStorage<T> *storage) :
			m_storage(storage) {
	}

	// -------------------------------------------------------------------------
	// Iterators
	// -------------------------------------------------------------------------

	auto begin() const {
		return m_storage->GetSparseSet().GetDense().begin();
	}

	auto end() const {
		return m_storage->GetSparseSet().GetDense().end();
	}

private:
	ComponentStorage<T> *m_storage;


};

