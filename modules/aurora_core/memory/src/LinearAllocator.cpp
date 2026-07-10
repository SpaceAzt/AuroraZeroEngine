/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      LinearAllocator.cpp
 *
 * Description:
 *      Linear memory allocator implementation.
 ******************************************************************************/

#include "LinearAllocator.h"

#include <new>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

LinearAllocator::LinearAllocator(
		std::size_t capacity) :
		m_capacity(capacity) {
	m_memory = new std::byte[m_capacity];
}

// -----------------------------------------------------------------------------

LinearAllocator::~LinearAllocator() {
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

void *LinearAllocator::Allocate(
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

void LinearAllocator::Free(
		void *ptr) {
	(void)ptr;

	// Linear allocator does not support individual deallocation.
}
// -----------------------------------------------------------------------------

void LinearAllocator::Reset() {
	m_offset = 0;

	m_stats.currentUsage = 0;

	m_stats.freeCount++;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

const MemoryStats &LinearAllocator::GetStats() const {
	return m_stats;
}

// -----------------------------------------------------------------------------

std::size_t LinearAllocator::Capacity() const {
	return m_capacity;
}

// -----------------------------------------------------------------------------

std::size_t LinearAllocator::Used() const {
	return m_offset;
}

// -----------------------------------------------------------------------------

std::size_t LinearAllocator::Remaining() const {
	return m_capacity - m_offset;
}
