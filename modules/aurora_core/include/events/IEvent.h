#pragma once

#include "EventCategory.h"
#include "EventType.h"

#include <string>

class IEvent {
public:
	virtual ~IEvent() = default;

	virtual EventType GetType() const = 0;

	virtual EventCategory GetCategory() const = 0;

	virtual const char *GetName() const = 0;

	virtual std::string ToString() const {
		return GetName();
	}
};
