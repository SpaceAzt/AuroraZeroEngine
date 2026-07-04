#include "ecs/systems/MovementSystem.h"

#include "AuroraLogger.h"
#include "ecs/Registry.h"

// -----------------------------------------------------------------------------
// Update
// -----------------------------------------------------------------------------

void MovementSystem::Update(
		Registry &registry,
		float deltaTime) {
	AuroraLogger::Info(
			"MovementSystem Update");
}
