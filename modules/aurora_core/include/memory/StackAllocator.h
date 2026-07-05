#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      StackAllocator.h
 *
 * Description:
 *      Stack (LIFO) memory allocator.
 ******************************************************************************/

#include "memory/IAllocator.h"
#include "memory/MemoryStats.h"

#include <cstddef>

class StackAllocator : public IAllocator {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	explicit StackAllocator(std::size_t capacity);

	~StackAllocator() override;

	// -------------------------------------------------------------------------
	// Memory
	// -------------------------------------------------------------------------

	void *Allocate(
			std::size_t size,
			std::size_t alignment = alignof(std::max_align_t))
			override;

	void Free(void *ptr) override;

	void Reset();

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
	// Memory
	// -------------------------------------------------------------------------

	std::byte *m_memory = nullptr;

	std::size_t m_capacity = 0;

	std::size_t m_offset = 0;

	MemoryStats m_stats;
};
