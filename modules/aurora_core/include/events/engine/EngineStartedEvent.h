#pragma once

#include "../EventMacros.h"
#include "../IEvent.h"

class EngineStartedEvent : public IEvent {
public:
	EVENT_CLASS_TYPE(EngineStarted)
	EVENT_CLASS_CATEGORY(Engine)
};
