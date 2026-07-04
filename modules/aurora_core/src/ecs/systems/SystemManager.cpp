#include "ecs/systems/SystemManager.h"

#include "ecs/Registry.h"
#include "ecs/systems/ISystem.h"

// -----------------------------------------------------------------------------
// AddSystem
// -----------------------------------------------------------------------------

void SystemManager::AddSystem(
		std::unique_ptr<ISystem> system) {
	m_systems.push_back(std::move(system));
}

// -----------------------------------------------------------------------------
// Update
// -----------------------------------------------------------------------------

void SystemManager::Update(
		Registry &registry,
		float deltaTime) {
	for (auto &system : m_systems) {
		system->Update(registry, deltaTime);
	}
}
