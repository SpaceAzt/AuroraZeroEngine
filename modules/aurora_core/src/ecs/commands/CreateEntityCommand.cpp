#include "ecs/commands/CreateEntityCommand.h"

#include "ecs/Registry.h"

// -----------------------------------------------------------------------------
// Execute
// -----------------------------------------------------------------------------

void CreateEntityCommand::Execute(
		Registry &registry) {
	registry.CreateEntity();
}
