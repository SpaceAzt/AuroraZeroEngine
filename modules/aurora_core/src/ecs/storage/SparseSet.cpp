#include "ecs/storage/SparseSet.h"

#include <algorithm>

// -----------------------------------------------------------------------------
// Insert
// -----------------------------------------------------------------------------

void SparseSet::Insert(EntityID entity) {
	if (Contains(entity)) {
		return;
	}

	if (entity >= m_sparse.size()) {
		m_sparse.resize(entity + 1, INVALID_INDEX);
	}

	m_sparse[entity] = m_dense.size();
	m_dense.push_back(entity);
}

// -----------------------------------------------------------------------------
// Remove
// -----------------------------------------------------------------------------

void SparseSet::Remove(EntityID entity) {
	if (!Contains(entity)) {
		return;
	}

	size_t index = m_sparse[entity];
	EntityID lastEntity = m_dense.back();

	m_dense[index] = lastEntity;
	m_sparse[lastEntity] = index;

	m_dense.pop_back();
	m_sparse[entity] = INVALID_INDEX;
}

// -----------------------------------------------------------------------------
// Contains
// -----------------------------------------------------------------------------

bool SparseSet::Contains(EntityID entity) const {
	if (entity >= m_sparse.size()) {
		return false;
	}

	return m_sparse[entity] != INVALID_INDEX;
}

// -----------------------------------------------------------------------------
// Clear
// -----------------------------------------------------------------------------

void SparseSet::Clear() {
	m_dense.clear();
	m_sparse.clear();
}

// -----------------------------------------------------------------------------
// Size
// -----------------------------------------------------------------------------

size_t SparseSet::Size() const {
	return m_dense.size();
}

// -----------------------------------------------------------------------------
// GetDense
// -----------------------------------------------------------------------------

const std::vector<EntityID> &SparseSet::GetDense() const {
	return m_dense;
}

// -----------------------------------------------------------------------------
// Get Dense Index
// -----------------------------------------------------------------------------

size_t SparseSet::GetDenseIndex(EntityID entity) const {
	if (!Contains(entity)) {
		return INVALID_INDEX;
	}

	return m_sparse[entity];
}

// -----------------------------------------------------------------------------
// Get Entity
// -----------------------------------------------------------------------------

EntityID SparseSet::GetEntity(size_t index) const {
	return m_dense[index];
}

