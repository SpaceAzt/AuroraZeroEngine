#pragma once

#include "IEvent.h"

#include <functional>
#include <unordered_map>
#include <vector>

class EventBus {
public:
	using Listener = std::function<void(IEvent &)>;

	static EventBus &Get();

	void Subscribe(
			EventType type,
			Listener listener);

	void Publish(
			IEvent &event);

	void Clear();

private:
	std::unordered_map<
			EventType,
			std::vector<Listener>>
			m_listeners;
};
