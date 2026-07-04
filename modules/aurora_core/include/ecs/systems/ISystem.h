#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      ISystem.h
 *
 * Description:
 *      Base interface for all ECS systems.
 ******************************************************************************/

class Registry;

class ISystem {
public:
	virtual ~ISystem() = default;

	virtual void Update(
			Registry &registry,
			float deltaTime) = 0;
};
