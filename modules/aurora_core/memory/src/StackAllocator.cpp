/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      StackAllocator.cpp
 *
 * Description:
 *      Stack memory allocator implementation.
 ******************************************************************************/

#include "StackAllocator.h"

#include <new>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

StackAllocator::StackAllocator(
		std::size_t capacity) :
		m_capacity(capacity) {
	m_memory = new std::byte[m_capacity];
}

// -----------------------------------------------------------------------------

StackAllocator::~StackAllocator() {
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

void *StackAllocator::Allocate(
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

void StackAllocator::Free(
		void *ptr) {
	(void)ptr;

	// -------------------------------------------------------------------------
	// TODO(v0.5)
	// Implement LIFO deallocation using allocation headers.
	// -------------------------------------------------------------------------
}

// -----------------------------------------------------------------------------
// Reset
// -----------------------------------------------------------------------------

void StackAllocator::Reset() {
	m_offset = 0;

	m_stats.currentUsage = 0;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

const MemoryStats &StackAllocator::GetStats() const {
	return m_stats;
}

// -----------------------------------------------------------------------------

std::size_t StackAllocator::Capacity() const {
	return m_capacity;
}

// -----------------------------------------------------------------------------

std::size_t StackAllocator::Used() const {
	return m_offset;
}

// -----------------------------------------------------------------------------

std::size_t StackAllocator::Remaining() const {
	return m_capacity - m_offset;
}
