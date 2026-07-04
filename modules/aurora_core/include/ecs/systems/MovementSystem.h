#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MovementSystem.h
 ******************************************************************************/

#include "ecs/systems/ISystem.h"

class MovementSystem : public ISystem {
public:
	void Update(
			Registry &registry,
			float deltaTime) override;
};
