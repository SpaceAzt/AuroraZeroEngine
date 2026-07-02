#pragma once

#include "IEvent.h"

#include <functional>

class EventDispatcher {
public:
	explicit EventDispatcher(IEvent &event) :
			m_event(event) {
	}

	template <typename T>
	bool Dispatch(const std::function<bool(T &)> &func) {
		if (m_event.GetType() == T::GetStaticType()) {
			return func(static_cast<T &>(m_event));
		}

		return false;
	}

private:
	IEvent &m_event;
};
