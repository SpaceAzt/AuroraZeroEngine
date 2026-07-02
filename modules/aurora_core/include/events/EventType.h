#pragma once
enum class EventType {
	None = 0,

	EngineStarted,
	EngineStopped,

	ModuleLoaded,
	ModuleUnloaded,

	WindowResize,
	WindowClose,

	KeyPressed,
	KeyReleased,

	MouseMoved,
	MouseButtonPressed
};
