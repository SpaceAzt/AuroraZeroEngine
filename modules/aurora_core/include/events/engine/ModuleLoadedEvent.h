#pragma once

#include "../EventMacros.h"
#include "../IEvent.h"

#include <string>

class ModuleLoadedEvent : public IEvent {
public:
	explicit ModuleLoadedEvent(const std::string &name) :
			m_name(name) {
	}

	EVENT_CLASS_TYPE(ModuleLoaded)
	EVENT_CLASS_CATEGORY(Engine)

	const std::string &GetModuleName() const {
		return m_name;
	}

private:
	std::string m_name;
};
