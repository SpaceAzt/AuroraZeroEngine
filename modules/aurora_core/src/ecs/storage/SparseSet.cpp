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
		m_sparse.resize(entity + 1, static_cast<size_t>(-1));
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
	m_sparse[entity] = static_cast<size_t>(-1);
}

// -----------------------------------------------------------------------------
// Contains
// -----------------------------------------------------------------------------

bool SparseSet::Contains(EntityID entity) const {
	if (entity >= m_sparse.size()) {
		return false;
	}

	return m_sparse[entity] != static_cast<size_t>(-1);
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
