#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MemoryStats.h
 *
 * Description:
 *      Memory allocator statistics.
 ******************************************************************************/

#include <cstddef>

struct MemoryStats {
	// -------------------------------------------------------------------------
	// Statistics
	// -------------------------------------------------------------------------

	std::size_t totalAllocated = 0;

	std::size_t totalFreed = 0;

	std::size_t currentUsage = 0;

	std::size_t peakUsage = 0;

	std::size_t allocationCount = 0;

	std::size_t freeCount = 0;
};
