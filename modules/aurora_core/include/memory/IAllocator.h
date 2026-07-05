#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      IAllocator.h
 *
 * Description:
 *      Base interface for all Aurora memory allocators.
 ******************************************************************************/

#include "memory/AllocationInfo.h"
#include "memory/MemoryStats.h"

#include <cstddef>

class IAllocator {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	virtual ~IAllocator() = default;

	// -------------------------------------------------------------------------
	// Memory
	// -------------------------------------------------------------------------

	[[nodiscard]]
	virtual void *Allocate(
			std::size_t size,
			std::size_t alignment = alignof(std::max_align_t)) = 0;

	virtual void Free(
			void *ptr) = 0;

	virtual void Reset() = 0;

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	virtual const MemoryStats &GetStats() const = 0;
};
