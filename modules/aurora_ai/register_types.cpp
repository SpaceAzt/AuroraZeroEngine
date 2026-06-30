#include "register_types.h"

#include <iostream>

void initialize_aurora_ai_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	std::cout << "Aurora AI Module Loaded!" << std::endl;
}

void uninitialize_aurora_ai_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	std::cout << "Aurora AI Module Unloaded!" << std::endl;
}
