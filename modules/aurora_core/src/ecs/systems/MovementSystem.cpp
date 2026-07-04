#include "ecs/systems/MovementSystem.h"

#include "ecs/Registry.h"
#include "ecs/components/TransformComponent.h"
#include "ecs/components/VelocityComponent.h"

// -----------------------------------------------------------------------------
// Update
// -----------------------------------------------------------------------------

void MovementSystem::Update(
		Registry &registry,
		float deltaTime) {
	auto view =
			registry.CreateMultiView<
					TransformComponent,
					VelocityComponent>();

	for (EntityID entityId : view) {
		Entity entity(entityId);



		auto &transform =
				registry.GetComponent<TransformComponent>(entity);

		auto &velocity =
				registry.GetComponent<VelocityComponent>(entity);

		transform.x += velocity.x * deltaTime;
		transform.y += velocity.y * deltaTime;
		transform.z += velocity.z * deltaTime;
	}
}
