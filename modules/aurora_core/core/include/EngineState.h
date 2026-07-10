#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      EngineState.h
 *
 * Description:
 *      Defines the lifecycle states of the Aurora Engine.
 ******************************************************************************/

enum class EngineState {
	// -------------------------------------------------------------------------
	// Engine Lifetime
	// -------------------------------------------------------------------------

	Created,

	Initializing,

	Running,

	Paused,

	ShuttingDown,

	Stopped
};

[[nodiscard]]
constexpr bool IsRunning(
		EngineState state) {
	return state == EngineState::Running;
}

[[nodiscard]]
constexpr bool IsStopped(
		EngineState state) {
	return state == EngineState::Stopped;
}
