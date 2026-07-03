#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      IComponentStorage.h
 *
 * Description:
 *      Base interface for all component storages.
 ******************************************************************************/

class IComponentStorage {
public:
	virtual ~IComponentStorage() = default;

	virtual void RemoveEntity(unsigned int entity) = 0;

	virtual void Clear() = 0;
};
