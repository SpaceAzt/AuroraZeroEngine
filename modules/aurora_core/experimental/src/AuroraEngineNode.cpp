#include "../include/AuroraEngineNode.h"

#include "../include/AuroraApplication.h"

using namespace godot;

static AuroraApplication g_application;

void AuroraEngineNode::_bind_methods() {
}

AuroraEngineNode::AuroraEngineNode() {
}

AuroraEngineNode::~AuroraEngineNode() {
}

void AuroraEngineNode::_ready() {
	g_application.Initialize();
}

void AuroraEngineNode::_process(double delta) {
	g_application.Update();
}

void AuroraEngineNode::_exit_tree() {
	g_application.Shutdown();
}
