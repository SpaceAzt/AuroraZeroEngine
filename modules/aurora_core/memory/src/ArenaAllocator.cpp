/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ArenaAllocator.cpp
 *
 * Description:
 *      Arena memory allocator implementation.
 ******************************************************************************/

#include "ArenaAllocator.h"

#include <new>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

ArenaAllocator::ArenaAllocator(
		std::size_t capacity) :
		m_capacity(capacity) {
	m_memory = new std::byte[m_capacity];
}

// -----------------------------------------------------------------------------

ArenaAllocator::~ArenaAllocator() {
	delete[] m_memory;

	m_memory = nullptr;

	m_capacity = 0;

	m_offset = 0;
}

// -----------------------------------------------------------------------------
// Memory
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Allocate
// -----------------------------------------------------------------------------

void *ArenaAllocator::Allocate(
		std::size_t size,
		std::size_t alignment) {
	(void)alignment;

	if (m_offset + size > m_capacity) {
		return nullptr;
	}

	void *memory = m_memory + m_offset;

	m_offset += size;

	m_stats.totalAllocated += size;
	m_stats.currentUsage += size;
	m_stats.allocationCount++;

	if (m_stats.currentUsage > m_stats.peakUsage) {
		m_stats.peakUsage = m_stats.currentUsage;
	}

	return memory;
}

// -----------------------------------------------------------------------------
// Free
// -----------------------------------------------------------------------------

void ArenaAllocator::Free(
		void *ptr) {
	(void)ptr;

	// -------------------------------------------------------------------------
	// TODO(v0.5)
	// Arena allocator does not support individual deallocation.
	// Memory is released using Reset().
	// -------------------------------------------------------------------------
}

// -----------------------------------------------------------------------------
// Reset
// -----------------------------------------------------------------------------

void ArenaAllocator::Reset() {
	m_offset = 0;

	m_stats.currentUsage = 0;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

const MemoryStats &ArenaAllocator::GetStats() const {
	return m_stats;
}

// -----------------------------------------------------------------------------

std::size_t ArenaAllocator::Capacity() const {
	return m_capacity;
}

// -----------------------------------------------------------------------------

std::size_t ArenaAllocator::Used() const {
	return m_offset;
}

// -----------------------------------------------------------------------------

std::size_t ArenaAllocator::Remaining() const {
	return m_capacity - m_offset;
}
