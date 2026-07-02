#pragma once

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class AuroraEngineNode : public Node {
	GDCLASS(AuroraEngineNode, Node);

protected:
	static void _bind_methods();

public:
	AuroraEngineNode();
	~AuroraEngineNode();

	void _ready() override;

	void _process(double delta) override;

	void _exit_tree() override;
};
