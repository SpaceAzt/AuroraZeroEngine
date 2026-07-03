#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      SparseSet.h
 *
 * Description:
 *      Sparse Set implementation for fast entity storage and lookup.
 ******************************************************************************/

#include <cstddef>
#include <cstdint>
#include <vector>

using EntityID = uint32_t;

class SparseSet {
public:
	SparseSet() = default;
	~SparseSet() = default;

	void Insert(EntityID entity);

	void Remove(EntityID entity);

	bool Contains(EntityID entity) const;

	void Clear();

	size_t Size() const;

	const std::vector<EntityID> &GetDense() const;

private:
	// -------------------------------------------------------------------------
	// TODO(v0.4):
	// Support iteration, views and component storage.
	// -------------------------------------------------------------------------

	std::vector<EntityID> m_dense;
	std::vector<size_t> m_sparse;
};
