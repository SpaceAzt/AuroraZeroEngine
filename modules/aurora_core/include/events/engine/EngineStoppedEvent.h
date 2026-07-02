#pragma once

#include "../EventMacros.h"
#include "../IEvent.h"

class EngineStoppedEvent : public IEvent {
public:
	EVENT_CLASS_TYPE(EngineStopped)
	EVENT_CLASS_CATEGORY(Engine)
};
