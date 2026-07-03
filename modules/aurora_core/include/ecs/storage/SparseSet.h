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
#include <limits>

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

	size_t GetDenseIndex(EntityID entity) const;

	EntityID GetEntity(size_t index) const;

	const std::vector<EntityID> &GetDense() const;

private:
	// -------------------------------------------------------------------------
	// TODO(v0.4):
	// Support iteration, views and component storage.
	// -------------------------------------------------------------------------
	static constexpr size_t INVALID_INDEX =
			std::numeric_limits<size_t>::max();

	std::vector<EntityID> m_dense;
	std::vector<size_t> m_sparse;
};
