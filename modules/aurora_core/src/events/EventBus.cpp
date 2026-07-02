#include "../../include/events/EventBus.h"

EventBus &EventBus::Get() {
	static EventBus bus;
	return bus;
}

void EventBus::Subscribe(
		EventType type,
		Listener listener) {
	m_listeners[type].push_back(listener);
}

void EventBus::Publish(
		IEvent &event) {
	auto it = m_listeners.find(event.GetType());

	if (it == m_listeners.end()) {
		return;
	}

	for (auto &listener : it->second) {
		listener(event);
	}
}

void EventBus::Clear() {
	m_listeners.clear();
}
