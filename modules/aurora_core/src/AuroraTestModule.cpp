// -----------------------------------------------------------------------------
// Aurora
// -----------------------------------------------------------------------------

#include "AuroraCore.h"
#include "AuroraLogger.h"
#include "AuroraTestModule.h"

// -----------------------------------------------------------------------------
// ECS Core
// -----------------------------------------------------------------------------

#include "ecs/ComponentManager.h"
#include "ecs/EntityManager.h"
#include "ecs/Registry.h"

// -----------------------------------------------------------------------------
// ECS Components
// -----------------------------------------------------------------------------

#include "ecs/components/TransformComponent.h"
#include "ecs/components/VelocityComponent.h"

// -----------------------------------------------------------------------------
// ECS Storage
// -----------------------------------------------------------------------------

#include "ecs/storage/ComponentStorage.h"
#include "ecs/storage/SparseSet.h"

// -----------------------------------------------------------------------------
// ECS Commands
// -----------------------------------------------------------------------------

#include "ecs/commands/CreateEntityCommand.h"
#include "ecs/commands/DestroyEntityCommand.h"
#include "ecs/commands/EntityCommandBuffer.h"

// -----------------------------------------------------------------------------
// ECS Systems
// -----------------------------------------------------------------------------

#include "ecs/systems/MovementSystem.h"
#include "ecs/systems/SystemManager.h"

// -----------------------------------------------------------------------------
// Events
// -----------------------------------------------------------------------------

#include "events/EventBus.h"
#include "events/engine/EngineStartedEvent.h"
#include "events/engine/EngineStoppedEvent.h"

// -----------------------------------------------------------------------------
// STL
// -----------------------------------------------------------------------------

#include <memory>

// -----------------------------------------------------------------------------
// Test Components
// -----------------------------------------------------------------------------

namespace {

struct DummyComponent {
	int value = 0;
};

} // namespace

// -----------------------------------------------------------------------------
// Initialize
// -----------------------------------------------------------------------------

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

	RunSparseSetTests();

	RunComponentStorageTests();

	RunRegistryComponentTests();

	RunViewTests();

	RunMultiViewTests();

	RunSystemManagerTests();

	RunMovementSystemTests();

	RunCommandBufferTests();

	RunECSTests();

	RunEventSystemTests();

	RunComponentManagerTests();

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

// -----------------------------------------------------------------------------
// Component Storage Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunComponentStorageTests() {
	AuroraLogger::Section("Component Storage Test");

	ComponentStorage<TransformComponent> storage;

	storage.Add(
			1,
			{ 10.0f, 20.0f, 30.0f });

	if (storage.Has(1)) {
		AuroraLogger::Success("Transform added.");
	}

	auto &transform = storage.Get(1);

	AuroraLogger::Info(
			"Position: (" +
			std::to_string(transform.x) + ", " +
			std::to_string(transform.y) + ", " +
			std::to_string(transform.z) + ")");

	storage.Remove(1);

	AuroraLogger::Info(
			storage.Has(1)
					? "Component still exists"
					: "Component removed");
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


// -----------------------------------------------------------------------------
// Registry Component Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunRegistryComponentTests() {
	AuroraLogger::Section("Registry Component Test");

	Registry registry;

	Entity player = registry.CreateEntity();

	registry.AddComponent<TransformComponent>(
			player,
			{ 10.0f, 20.0f, 30.0f });

	if (registry.HasComponent<TransformComponent>(player)) {
		AuroraLogger::Success("Registry component added.");
	} else {
		AuroraLogger::Error("Registry component NOT added.");
		return;
	}

	auto &transform =
			registry.GetComponent<TransformComponent>(player);

	AuroraLogger::Info(
			"Position: (" +
			std::to_string(transform.x) + ", " +
			std::to_string(transform.y) + ", " +
			std::to_string(transform.z) + ")");

	transform.x += 5.0f;

	AuroraLogger::Info(
			"Updated X: " +
			std::to_string(transform.x));

	registry.RemoveComponent<TransformComponent>(player);

	if (!registry.HasComponent<TransformComponent>(player)) {
		AuroraLogger::Success("Registry component removed.");
	} else {
		AuroraLogger::Error("Registry component removal failed.");
	}
}

// -----------------------------------------------------------------------------
// View Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunViewTests() {
	AuroraLogger::Section("ECS View Test");

	Registry registry;

	Entity player = registry.CreateEntity();
	Entity enemy = registry.CreateEntity();

	registry.AddComponent<TransformComponent>(
			player,
			{ 10.0f, 20.0f, 30.0f });

	registry.AddComponent<TransformComponent>(
			enemy,
			{ 40.0f, 50.0f, 60.0f });

	auto view = registry.CreateView<TransformComponent>();

	size_t count = 0;

	for (EntityID entityId : view) {
		++count;

		AuroraLogger::Info(
				"Entity ID: " +
				std::to_string(entityId));
	}

	AuroraLogger::Success(
			"View Count: " +
			std::to_string(count));
}

// -----------------------------------------------------------------------------
// System Manager Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunSystemManagerTests() {
	AuroraLogger::Section("System Manager Test");

	Registry registry;

	SystemManager systemManager;

	systemManager.AddSystem(
			std::make_unique<MovementSystem>());

	systemManager.Update(
			registry,
			1.0f);

	AuroraLogger::Success(
			"SystemManager updated successfully.");
}

// -----------------------------------------------------------------------------
// Movement System Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunMovementSystemTests() {
	AuroraLogger::Section("Movement System Test");

	Registry registry;

	SystemManager systems;

	Entity player = registry.CreateEntity();

	registry.AddComponent<TransformComponent>(
			player,
			{ 10.0f, 20.0f, 30.0f });

	registry.AddComponent<VelocityComponent>(
			player,
			{ 5.0f, 0.0f, 0.0f });

	auto &before =
			registry.GetComponent<TransformComponent>(player);

	AuroraLogger::Info(
			"Before: (" +
			std::to_string(before.x) + ", " +
			std::to_string(before.y) + ", " +
			std::to_string(before.z) + ")");

	systems.AddSystem(
			std::make_unique<MovementSystem>());

	systems.Update(registry, 1.0f);

	auto &after =
			registry.GetComponent<TransformComponent>(player);

	AuroraLogger::Info(
			"After: (" +
			std::to_string(after.x) + ", " +
			std::to_string(after.y) + ", " +
			std::to_string(after.z) + ")");

	if (after.x == 15.0f &&
			after.y == 20.0f &&
			after.z == 30.0f) {
		AuroraLogger::Success(
				"Movement successful.");
	} else {
		AuroraLogger::Error(
				"Movement failed.");
	}
}

// -----------------------------------------------------------------------------
// MultiView Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunMultiViewTests() {
	AuroraLogger::Section("ECS MultiView Test");

	Registry registry;

	// -------------------------------------------------------------------------
	// Create entities
	// -------------------------------------------------------------------------

	Entity entity1 = registry.CreateEntity();
	Entity entity2 = registry.CreateEntity();
	Entity entity3 = registry.CreateEntity();

	// -------------------------------------------------------------------------
	// Entity 1
	// Transform + Velocity
	// -------------------------------------------------------------------------

	registry.AddComponent<TransformComponent>(
			entity1,
			{ 0.0f, 0.0f, 0.0f });

	registry.AddComponent<VelocityComponent>(
			entity1,
			{ 1.0f, 0.0f, 0.0f });

	// -------------------------------------------------------------------------
	// Entity 2
	// Transform only
	// -------------------------------------------------------------------------

	registry.AddComponent<TransformComponent>(
			entity2,
			{ 10.0f, 0.0f, 0.0f });

	// -------------------------------------------------------------------------
	// Entity 3
	// Transform + Velocity
	// -------------------------------------------------------------------------

	registry.AddComponent<TransformComponent>(
			entity3,
			{ 20.0f, 0.0f, 0.0f });

	registry.AddComponent<VelocityComponent>(
			entity3,
			{ 2.0f, 0.0f, 0.0f });

	// -------------------------------------------------------------------------
	// Create MultiView
	// -------------------------------------------------------------------------

	auto view =
			registry.CreateMultiView<
					TransformComponent,
					VelocityComponent>();

	// -------------------------------------------------------------------------
	// Iterate
	// -------------------------------------------------------------------------

	size_t count = 0;

	for (EntityID entity : view) {
		AuroraLogger::Info(
				"Entity ID: " +
				std::to_string(entity));

		++count;
	}

	// -------------------------------------------------------------------------
	// Validation
	// -------------------------------------------------------------------------

	if (count == 2) {
		AuroraLogger::Success(
				"MultiView Count: " +
				std::to_string(count));
	} else {
		AuroraLogger::Error(
				"Unexpected entity count: " +
				std::to_string(count));
	}
}

// -----------------------------------------------------------------------------
// Command Buffer Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunCommandBufferTests() {
	AuroraLogger::Section("Command Buffer Test");

	Registry registry;

	EntityCommandBuffer commandBuffer;

	Entity player = registry.CreateEntity();

	// -------------------------------------------------------------------------
	// Entity Creation
	// -------------------------------------------------------------------------

	if (!registry.IsAlive(player)) {
		AuroraLogger::Error(
				"Player creation failed.");
		return;
	}

	AuroraLogger::Success(
			"Player created.");

	// -------------------------------------------------------------------------
	// Queue Destroy Command
	// -------------------------------------------------------------------------

	commandBuffer.Enqueue(
			std::make_unique<DestroyEntityCommand>(player));

	AuroraLogger::Info(
			"DestroyEntityCommand queued.");

	// -------------------------------------------------------------------------
	// Entity should still be alive
	// -------------------------------------------------------------------------

	if (registry.IsAlive(player)) {
		AuroraLogger::Success(
				"Player still alive before Flush.");
	} else {
		AuroraLogger::Error(
				"Player destroyed too early.");
		return;
	}

	// -------------------------------------------------------------------------
	// Execute Commands
	// -------------------------------------------------------------------------

	commandBuffer.Flush(registry);

	AuroraLogger::Info(
			"Command buffer flushed.");

	// -------------------------------------------------------------------------
	// Entity should now be destroyed
	// -------------------------------------------------------------------------

	if (!registry.IsAlive(player)) {
		AuroraLogger::Success(
				"Player destroyed after Flush.");
	} else {
		AuroraLogger::Error(
				"Player was not destroyed.");
	}
}

// -----------------------------------------------------------------------------
// Component Manager Tests
// -----------------------------------------------------------------------------

void AuroraTestModule::RunComponentManagerTests() {
	AuroraLogger::Section("Component Manager Test");

	ComponentManager componentManager;

	// -------------------------------------------------------------------------
	// Storage should not exist initially
	// -------------------------------------------------------------------------

	if (!componentManager.HasStorage<TransformComponent>()) {
		AuroraLogger::Success(
				"Transform storage not registered.");
	} else {
		AuroraLogger::Error(
				"Transform storage should not exist.");
	}

	// -------------------------------------------------------------------------
	// Register Transform storage
	// -------------------------------------------------------------------------

	componentManager.RegisterStorage<TransformComponent>();

	if (componentManager.HasStorage<TransformComponent>()) {
		AuroraLogger::Success(
				"Transform storage registered.");
	} else {
		AuroraLogger::Error(
				"Transform storage registration failed.");
	}

	// -------------------------------------------------------------------------
	// Retrieve Transform storage
	// -------------------------------------------------------------------------

	auto *transformStorage =
			componentManager.GetStorage<TransformComponent>();

	if (transformStorage != nullptr) {
		AuroraLogger::Success(
				"Transform storage retrieved.");
	} else {
		AuroraLogger::Error(
				"Transform storage is nullptr.");
	}

	// -------------------------------------------------------------------------
	// Duplicate registration
	// -------------------------------------------------------------------------

	componentManager.RegisterStorage<TransformComponent>();

	AuroraLogger::Success(
			"Duplicate registration ignored.");

	// -------------------------------------------------------------------------
	// Register Velocity storage
	// -------------------------------------------------------------------------

	componentManager.RegisterStorage<VelocityComponent>();

	if (componentManager.HasStorage<VelocityComponent>()) {
		AuroraLogger::Success(
				"Velocity storage registered.");
	} else {
		AuroraLogger::Error(
				"Velocity storage registration failed.");
	}

	// -------------------------------------------------------------------------
	// Retrieve Velocity storage
	// -------------------------------------------------------------------------

	auto *velocityStorage =
			componentManager.GetStorage<VelocityComponent>();

	if (velocityStorage != nullptr) {
		AuroraLogger::Success(
				"Velocity storage retrieved.");
	} else {
		AuroraLogger::Error(
				"Velocity storage is nullptr.");
	}

	// -------------------------------------------------------------------------
	// Storages must be different
	// -------------------------------------------------------------------------

	if (transformStorage !=
			reinterpret_cast<ComponentStorage<TransformComponent> *>(velocityStorage)) {
		AuroraLogger::Success(
				"Storages are unique.");
	} else {
		AuroraLogger::Error(
				"Storages should be unique.");
	}

	// -------------------------------------------------------------------------
	// Missing storage
	// -------------------------------------------------------------------------

	if (!componentManager.HasStorage<DummyComponent>()) {
		AuroraLogger::Success(
				"Dummy storage correctly absent.");
	} else {
		AuroraLogger::Error(
				"Dummy storage should not exist.");
	}

	auto *dummyStorage =
			componentManager.GetStorage<DummyComponent>();

	if (dummyStorage == nullptr) {
		AuroraLogger::Success(
				"Missing storage returned nullptr.");
	} else {
		AuroraLogger::Error(
				"Expected nullptr.");
	}
}
