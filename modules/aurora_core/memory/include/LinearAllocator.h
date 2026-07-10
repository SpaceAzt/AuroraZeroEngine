#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LinearAllocator.h
 *
 * Description:
 *      High-performance linear memory allocator.
 ******************************************************************************/

#include "IAllocator.h"

#include <cstddef>

class LinearAllocator final : public IAllocator {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	explicit LinearAllocator(std::size_t capacity);

	~LinearAllocator() override;

	// -------------------------------------------------------------------------
	// Memory
	// -------------------------------------------------------------------------

	[[nodiscard]]
	void *Allocate(
			std::size_t size,
			std::size_t alignment = alignof(std::max_align_t)) override;

	void Free(void *ptr) override;

	void Reset() override;

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	const MemoryStats &GetStats() const override;

	[[nodiscard]]
	std::size_t Capacity() const;

	[[nodiscard]]
	std::size_t Used() const;

	[[nodiscard]]
	std::size_t Remaining() const;

private:
	// -------------------------------------------------------------------------
	// Memory Block
	// -------------------------------------------------------------------------

	std::byte *m_memory = nullptr;

	std::size_t m_capacity = 0;

	std::size_t m_offset = 0;

	MemoryStats m_stats;
};
