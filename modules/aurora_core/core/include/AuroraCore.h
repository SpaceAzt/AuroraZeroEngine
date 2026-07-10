#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      AuroraCore.h
 *
 * Description:
 *      Main engine core.
 ******************************************************************************/

#include "EngineContext.h"

class AuroraCore {
public:
	// -------------------------------------------------------------------------
	// Singleton
	// -------------------------------------------------------------------------

	static AuroraCore &Get();

	// -------------------------------------------------------------------------
	// Engine Lifecycle
	// -------------------------------------------------------------------------

	bool Initialize();

	void Update();

	void Shutdown();

	void Stop();

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	bool IsInitialized() const;

	[[nodiscard]]
	bool IsRunning() const;

	[[nodiscard]]
	EngineContext &GetContext();

	[[nodiscard]]
	const EngineContext &GetContext() const;

private:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	AuroraCore();

	~AuroraCore();

	AuroraCore(const AuroraCore &) = delete;
	AuroraCore &operator=(const AuroraCore &) = delete;

private:
	EngineContext m_context;

	bool m_initialized = false;

	bool m_running = false;
};
