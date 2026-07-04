#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      MovementSystem.h
 *
 * Description:
 *      Updates TransformComponent using VelocityComponent.
 ******************************************************************************/

#include "ecs/systems/ISystem.h"

class MovementSystem : public ISystem {
public:
	// -------------------------------------------------------------------------
	// ISystem
	// -------------------------------------------------------------------------

	void Update(
			Registry &registry,
			float deltaTime) override;
};
