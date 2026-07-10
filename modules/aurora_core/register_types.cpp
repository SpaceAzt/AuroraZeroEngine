#include "register_types.h"
#include "AuroraApplication.h"

#include <iostream>

static AuroraApplication g_application;

void initialize_aurora_core_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	g_application.Initialize();
}

void uninitialize_aurora_core_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	g_application.Shutdown();
}
