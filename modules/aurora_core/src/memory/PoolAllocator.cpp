/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      PoolAllocator.cpp
 *
 * Description:
 *      Fixed-size pool allocator implementation.
 ******************************************************************************/

#include "memory/PoolAllocator.h"

#include <new>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

PoolAllocator::PoolAllocator(
		std::size_t blockSize,
		std::size_t blockCount) :
		m_blockSize(blockSize),
		m_blockCount(blockCount) {
	m_memory = new std::byte[m_blockSize * m_blockCount];

	// -------------------------------------------------------------------------
	// Build Free List
	// -------------------------------------------------------------------------

	m_freeList = reinterpret_cast<FreeBlock *>(m_memory);

	FreeBlock *current = m_freeList;

	for (std::size_t i = 0; i < m_blockCount - 1; ++i) {
		auto *next =
				reinterpret_cast<FreeBlock *>(
						m_memory + (i + 1) * m_blockSize);

		current->next = next;

		current = next;
	}

	current->next = nullptr;
}

// -----------------------------------------------------------------------------

PoolAllocator::~PoolAllocator() {
	delete[] m_memory;

	m_memory = nullptr;

	m_freeList = nullptr;

	m_blockSize = 0;

	m_blockCount = 0;

	m_usedBlocks = 0;
}

// -----------------------------------------------------------------------------
// Memory
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Allocate
// -----------------------------------------------------------------------------

void *PoolAllocator::Allocate(
		std::size_t size,
		std::size_t alignment) {
	(void)alignment;

	if (size > m_blockSize) {
		return nullptr;
	}

	if (m_freeList == nullptr) {
		return nullptr;
	}

	FreeBlock *block = m_freeList;

	m_freeList = block->next;

	++m_usedBlocks;

	m_stats.allocationCount++;
	m_stats.totalAllocated += m_blockSize;
	m_stats.currentUsage += m_blockSize;

	if (m_stats.currentUsage > m_stats.peakUsage) {
		m_stats.peakUsage = m_stats.currentUsage;
	}

	return block;
}

// -----------------------------------------------------------------------------
// Free
// -----------------------------------------------------------------------------

void PoolAllocator::Free(
		void *ptr) {
	if (ptr == nullptr) {
		return;
	}

	auto *block =
			static_cast<FreeBlock *>(ptr);

	block->next = m_freeList;

	m_freeList = block;

	if (m_usedBlocks > 0) {
		--m_usedBlocks;
	}

	if (m_stats.currentUsage >= m_blockSize) {
		m_stats.currentUsage -= m_blockSize;
	}
}

// -----------------------------------------------------------------------------
// Reset
// -----------------------------------------------------------------------------

void PoolAllocator::Reset() {
	m_freeList = reinterpret_cast<FreeBlock *>(m_memory);

	FreeBlock *current = m_freeList;

	for (std::size_t i = 0; i < m_blockCount - 1; ++i) {
		auto *next =
				reinterpret_cast<FreeBlock *>(
						m_memory + (i + 1) * m_blockSize);

		current->next = next;

		current = next;
	}

	current->next = nullptr;

	m_usedBlocks = 0;

	m_stats.currentUsage = 0;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

const MemoryStats &PoolAllocator::GetStats() const {
	return m_stats;
}

// -----------------------------------------------------------------------------

std::size_t PoolAllocator::BlockSize() const {
	return m_blockSize;
}

// -----------------------------------------------------------------------------

std::size_t PoolAllocator::BlockCount() const {
	return m_blockCount;
}

// -----------------------------------------------------------------------------

std::size_t PoolAllocator::UsedBlocks() const {
	return m_usedBlocks;
}

// -----------------------------------------------------------------------------

std::size_t PoolAllocator::FreeBlocks() const {
	return m_blockCount - m_usedBlocks;
}

// -----------------------------------------------------------------------------

std::size_t PoolAllocator::Capacity() const {
	return m_blockSize * m_blockCount;
}
