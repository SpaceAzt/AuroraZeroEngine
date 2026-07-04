#include "ecs/commands/EntityCommandBuffer.h"

#include "ecs/Registry.h"

#include <utility>

// -----------------------------------------------------------------------------
// Lifetime
// -----------------------------------------------------------------------------

EntityCommandBuffer::EntityCommandBuffer() = default;

EntityCommandBuffer::~EntityCommandBuffer() = default;

// -----------------------------------------------------------------------------
// Enqueue
// -----------------------------------------------------------------------------

void EntityCommandBuffer::Enqueue(
		std::unique_ptr<ICommand> command) {
	m_commands.emplace_back(std::move(command));
}

// -----------------------------------------------------------------------------
// Flush
// -----------------------------------------------------------------------------

void EntityCommandBuffer::Flush(
		Registry &registry) {
	if (m_commands.empty()) {
		return;
	}

	for (auto &command : m_commands) {
		command->Execute(registry);
	}

	m_commands.clear();
}


