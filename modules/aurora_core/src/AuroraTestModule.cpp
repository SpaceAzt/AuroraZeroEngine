#include "../include/AuroraTestModule.h"
#include "../include/events/EventBus.h"
#include "../include/events/engine/EngineStartedEvent.h"
#include "../include/AuroraLogger.h"

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

	EventBus::Get().Subscribe(
			EventType::EngineStarted,
			[](IEvent &event) {
				AuroraLogger::Success(
						std::string("Received Event: ") + event.GetName());
			});

	EngineStartedEvent event;

	EventBus::Get().Publish(event);

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
	AuroraLogger::Info("AuroraTestModule Shutdown");
}
