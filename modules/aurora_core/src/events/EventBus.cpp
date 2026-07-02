#include "../../include/events/EventBus.h"
#include "../../include/AuroraLogger.h"

EventBus &EventBus::Get() {
	static EventBus bus;
	return bus;
}

// -----------------------------------------------------------------------------
// TODO(v0.3):
// Move EventBus diagnostic logs to Debug/Trace log level.
// These logs are intentionally kept during early engine development
// to help validate the event system.
// -----------------------------------------------------------------------------


void EventBus::Subscribe(
		EventType type,
		Listener listener) {
	auto &listeners = m_listeners[type];

	listeners.push_back(listener);

	AuroraLogger::Info(
			"Listener registered. Total listeners: " + std::to_string(listeners.size()));
}

// -----------------------------------------------------------------------------
// TODO(v0.3):
// Replace Info logs with Debug/Trace logs once the logging system
// supports multiple verbosity levels.
// -----------------------------------------------------------------------------

void EventBus::Publish(IEvent &event) {
	AuroraLogger::Info(
			std::string("Publishing event: ") + event.GetName());

	auto it = m_listeners.find(event.GetType());

	if (it == m_listeners.end()) {
		AuroraLogger::Warning("No listeners found.");
		return;
	}

	AuroraLogger::Info(
			"Listener count: " + std::to_string(it->second.size()));

	for (auto &listener : it->second) {
		listener(event);
	}
}

void EventBus::Clear() {
	m_listeners.clear();
}
