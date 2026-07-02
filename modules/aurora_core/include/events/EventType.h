#pragma once
enum class EventType {
	None = 0,

	EngineStarted,
	EngineStopped,

	WindowResize,
	WindowClose,

	KeyPressed,
	KeyReleased,

	MouseMoved,
	MouseButtonPressed
};
