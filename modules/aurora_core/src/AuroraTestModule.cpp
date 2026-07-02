#include "../include/AuroraTestModule.h"
#include "../include/events/EventBus.h"
#include "../include/events/engine/EngineStartedEvent.h"
#include "../include/AuroraLogger.h"
#include "../include/events/engine/EngineStoppedEvent.h"
#include "../include/ecs/Registry.h"
#include "../include/ecs/EntityManager.h"

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

	// -----------------------------------------------------------------------------
	// ECS Foundation Test
	// -----------------------------------------------------------------------------

	Registry registry;

	EntityManager entityManager(registry);

	Entity player = entityManager.Create();
	Entity enemy = entityManager.Create();

	AuroraLogger::Success(
			"Player Entity ID: " +
			std::to_string(player.GetId()));

	AuroraLogger::Success(
			"Enemy Entity ID: " +
			std::to_string(enemy.GetId()));

	entityManager.Destroy(enemy);

	AuroraLogger::Info(
			registry.IsAlive(enemy)
					? "Enemy Alive"
					: "Enemy Destroyed");

	AuroraLogger::Section("ECS Foundation Test");



	EventBus::Get().Subscribe(
			EventType::EngineStarted,
			[](IEvent &event) {
				AuroraLogger::Success(
						std::string("Received: ") + event.ToString());
			});

	EventBus::Get().Subscribe(
			EventType::EngineStopped,
			[](IEvent &event) {
				AuroraLogger::Info(
						std::string("Received: ") + event.ToString());
			});

	AuroraLogger::Section("Event System Test");

	return true;
}

void AuroraTestModule::Update() {
	static int counter = 0;

	++counter;

	if (counter % 60 == 0) {
		AuroraLogger::Info("AuroraTestModule Update");
	}
}

void AuroraTestModule::Shutdown() {
	AuroraLogger::Warning(">>> AuroraTestModule::Shutdown entered");

	AuroraLogger::Info("AuroraTestModule Shutdown");

	AuroraLogger::Warning("<<< AuroraTestModule::Shutdown finished");
}

