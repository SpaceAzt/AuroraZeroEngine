#include "../include/AuroraTestModule.h"
#include "../include/events/EventBus.h"
#include "../include/events/engine/EngineStartedEvent.h"
#include "../include/AuroraLogger.h"
#include "../include/events/engine/EngineStoppedEvent.h"
#include "../include/ecs/Registry.h"
#include "../include/ecs/EntityManager.h"
#include "../include/ecs/storage/SparseSet.h"


// -----------------------------------------------------------------------------
// Initialize
// -----------------------------------------------------------------------------

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

	RunSparseSetTests();
    RunECSTests();
	RunEventSystemTests();

	return true;
}

// -----------------------------------------------------------------------------
// ECS Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunECSTests() {
	AuroraLogger::Section("ECS Foundation Test");

	Registry registry;

	EntityManager entityManager(registry);

	Entity player = entityManager.Create();
	Entity enemy = entityManager.Create();

	AuroraLogger::Success(
			"Created Player Entity (ID: " +
			std::to_string(player.GetId()) + ")");

	AuroraLogger::Success(
			"Created Enemy Entity (ID: " +
			std::to_string(enemy.GetId()) + ")");

	entityManager.Destroy(enemy);

	if (!registry.IsAlive(enemy)) {
		AuroraLogger::Success("Enemy Entity successfully destroyed");
	} else {
		AuroraLogger::Error("Failed to destroy Enemy Entity");
	}
}

// -----------------------------------------------------------------------------
// Event Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunEventSystemTests() {
	AuroraLogger::Section("Event System Test");

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
}

// -----------------------------------------------------------------------------
// SparseSet Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunSparseSetTests() {
	AuroraLogger::Section("Sparse Set Test");

	SparseSet set;

	set.Insert(1);
	set.Insert(5);
	set.Insert(10);

	AuroraLogger::Info(
			"Size: " + std::to_string(set.Size()));

	AuroraLogger::Info(
			set.Contains(5)
					? "Entity 5 Found"
					: "Entity 5 Missing");

	set.Remove(5);

	AuroraLogger::Info(
			set.Contains(5)
					? "Entity 5 Found"
					: "Entity 5 Removed");

	AuroraLogger::Info(
			"Size: " + std::to_string(set.Size()));

	set.Insert(5);

	AuroraLogger::Info(
			set.Contains(5)
					? "Entity 5 Reinserted"
					: "Insert Failed");

	AuroraLogger::Info(
			"Size: " + std::to_string(set.Size()));
}

void AuroraTestModule::Update() {
	static int counter = 0;

	++counter;

	if (counter % 60 == 0) {
		AuroraLogger::Info("AuroraTestModule Update");
	}
}

void AuroraTestModule::Shutdown() {
	
	AuroraLogger::Info("AuroraTestModule Shutdown");

}


