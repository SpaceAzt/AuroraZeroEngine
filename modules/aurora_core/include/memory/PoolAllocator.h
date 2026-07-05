#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      PoolAllocator.h
 *
 * Description:
 *      Fixed-size pool memory allocator.
 ******************************************************************************/

#include "memory/IAllocator.h"
#include "memory/MemoryStats.h"

#include <cstddef>

class PoolAllocator : public IAllocator {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	PoolAllocator(
			std::size_t blockSize,
			std::size_t blockCount);

	~PoolAllocator() override;

	// -------------------------------------------------------------------------
	// Memory
	// -------------------------------------------------------------------------

	void *Allocate(
			std::size_t size,
			std::size_t alignment = alignof(std::max_align_t))
			override;

	void Free(
			void *ptr) override;

	void Reset();

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	const MemoryStats &GetStats() const override;

	[[nodiscard]]
	std::size_t BlockSize() const;

	[[nodiscard]]
	std::size_t BlockCount() const;

	[[nodiscard]]
	std::size_t UsedBlocks() const;

	[[nodiscard]]
	std::size_t FreeBlocks() const;

	[[nodiscard]]
	std::size_t Capacity() const;

private:
	// -------------------------------------------------------------------------
	// Free List Node
	// -------------------------------------------------------------------------

	struct FreeBlock {
		FreeBlock *next = nullptr;
	};

	// -------------------------------------------------------------------------
	// Memory
	// -------------------------------------------------------------------------

	std::byte *m_memory = nullptr;

	FreeBlock *m_freeList = nullptr;

	std::size_t m_blockSize = 0;

	std::size_t m_blockCount = 0;

	std::size_t m_usedBlocks = 0;

	MemoryStats m_stats;
};
