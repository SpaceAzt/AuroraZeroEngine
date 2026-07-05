#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MemoryManager.h
 *
 * Description:
 *      Central memory management system.
 ******************************************************************************/

#include "memory/ArenaAllocator.h"
#include "memory/LinearAllocator.h"
#include "memory/PoolAllocator.h"
#include "memory/StackAllocator.h"

#include <cstddef>

class MemoryManager {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	MemoryManager();

	~MemoryManager();

	// -------------------------------------------------------------------------
	// Initialization
	// -------------------------------------------------------------------------

	void Initialize();

	void Shutdown();

	void Reset();

	// -------------------------------------------------------------------------
	// Allocators
	// -------------------------------------------------------------------------

	[[nodiscard]]
	LinearAllocator &GetLinearAllocator();

	[[nodiscard]]
	StackAllocator &GetStackAllocator();

	[[nodiscard]]
	PoolAllocator &GetPoolAllocator();

	[[nodiscard]]
	ArenaAllocator &GetArenaAllocator();

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	bool IsInitialized() const;

	[[nodiscard]]
	std::size_t TotalMemory() const;

	[[nodiscard]]
	const MemoryStats &GetLinearStats() const;

	[[nodiscard]]
	const MemoryStats &GetStackStats() const;

	[[nodiscard]]
	const MemoryStats &GetPoolStats() const;

	[[nodiscard]]
	const MemoryStats &GetArenaStats() const;

private:
	// -------------------------------------------------------------------------
	// Default Configuration
	// -------------------------------------------------------------------------

	static constexpr std::size_t LINEAR_SIZE = 1024 * 1024;

	static constexpr std::size_t STACK_SIZE = 1024 * 1024;

	static constexpr std::size_t ARENA_SIZE = 2 * 1024 * 1024;

	static constexpr std::size_t POOL_BLOCK_SIZE = 64;

	static constexpr std::size_t POOL_BLOCK_COUNT = 1024;

	// -------------------------------------------------------------------------
	// Allocators
	// -------------------------------------------------------------------------

	LinearAllocator m_linearAllocator;

	StackAllocator m_stackAllocator;

	PoolAllocator m_poolAllocator;

	ArenaAllocator m_arenaAllocator;

	// -------------------------------------------------------------------------
	// State
	// -------------------------------------------------------------------------

	bool m_initialized = false;
};
