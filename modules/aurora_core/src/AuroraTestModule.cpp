#include "../include/AuroraTestModule.h"
#include "../include/events/EventBus.h"
#include "../include/events/engine/EngineStartedEvent.h"
#include "../include/AuroraLogger.h"
#include "../include/events/engine/EngineStoppedEvent.h"

bool AuroraTestModule::Initialize() {
	AuroraLogger::Success("AuroraTestModule Initialized");

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

