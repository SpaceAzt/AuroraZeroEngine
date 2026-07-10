#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      AllocationInfo.h
 *
 * Description:
 *      Describes a single memory allocation.
 ******************************************************************************/

#include <cstddef>

struct AllocationInfo {
	// -------------------------------------------------------------------------
	// Allocation Information
	// -------------------------------------------------------------------------

	void *address = nullptr;

	std::size_t size = 0;

	std::size_t alignment = alignof(std::max_align_t);
};
