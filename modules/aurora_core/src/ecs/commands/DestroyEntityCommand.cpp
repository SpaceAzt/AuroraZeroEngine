#include "ecs/commands/DestroyEntityCommand.h"

#include "ecs/Registry.h"

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

DestroyEntityCommand::DestroyEntityCommand(
		Entity entity) :
		m_entity(entity) {
}

// -----------------------------------------------------------------------------
// Execute
// -----------------------------------------------------------------------------

void DestroyEntityCommand::Execute(
		Registry &registry) {
	registry.DestroyEntity(m_entity);
}
