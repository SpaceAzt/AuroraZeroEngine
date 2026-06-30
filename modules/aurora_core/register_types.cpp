#include "register_types.h"

#include <iostream>

void initialize_aurora_core_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	std::cout << "[Aurora] Core Initialized" << std::endl;
}

void uninitialize_aurora_core_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	std::cout << "[Aurora] Core Shutdown" << std::endl;
}
