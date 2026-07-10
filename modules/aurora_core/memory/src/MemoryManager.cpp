/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MemoryManager.cpp
 *
 * Description:
 *      Central memory management implementation.
 ******************************************************************************/

#include "MemoryManager.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

MemoryManager::MemoryManager() :
		m_linearAllocator(LINEAR_SIZE),
		m_stackAllocator(STACK_SIZE),
		m_poolAllocator(
				POOL_BLOCK_SIZE,
				POOL_BLOCK_COUNT),
		m_arenaAllocator(ARENA_SIZE) {
}

// -----------------------------------------------------------------------------

MemoryManager::~MemoryManager() {
	Shutdown();
}

// -----------------------------------------------------------------------------
// Initialization
// -----------------------------------------------------------------------------

void MemoryManager::Initialize() {
	if (m_initialized) {
		return;
	}

	m_initialized = true;
}

// -----------------------------------------------------------------------------

void MemoryManager::Shutdown() {
	if (!m_initialized) {
		return;
	}

	Reset();

	m_initialized = false;
}

// -----------------------------------------------------------------------------

void MemoryManager::Reset() {
	m_linearAllocator.Reset();

	m_stackAllocator.Reset();

	m_poolAllocator.Reset();

	m_arenaAllocator.Reset();
}

// -----------------------------------------------------------------------------
// Allocators
// -----------------------------------------------------------------------------

LinearAllocator &MemoryManager::GetLinearAllocator() {
	return m_linearAllocator;
}

// -----------------------------------------------------------------------------

StackAllocator &MemoryManager::GetStackAllocator() {
	return m_stackAllocator;
}

// -----------------------------------------------------------------------------

PoolAllocator &MemoryManager::GetPoolAllocator() {
	return m_poolAllocator;
}

// -----------------------------------------------------------------------------

ArenaAllocator &MemoryManager::GetArenaAllocator() {
	return m_arenaAllocator;
}

// -----------------------------------------------------------------------------
// Information
// -----------------------------------------------------------------------------

bool MemoryManager::IsInitialized() const {
	return m_initialized;
}

// -----------------------------------------------------------------------------

std::size_t MemoryManager::TotalMemory() const {
	return m_linearAllocator.Capacity() + m_stackAllocator.Capacity() + m_poolAllocator.Capacity() + m_arenaAllocator.Capacity();
}

// -----------------------------------------------------------------------------

const MemoryStats &MemoryManager::GetLinearStats() const {
	return m_linearAllocator.GetStats();
}

// -----------------------------------------------------------------------------

const MemoryStats &MemoryManager::GetStackStats() const {
	return m_stackAllocator.GetStats();
}

// -----------------------------------------------------------------------------

const MemoryStats &MemoryManager::GetPoolStats() const {
	return m_poolAllocator.GetStats();
}

// -----------------------------------------------------------------------------

const MemoryStats &MemoryManager::GetArenaStats() const {
	return m_arenaAllocator.GetStats();
}
