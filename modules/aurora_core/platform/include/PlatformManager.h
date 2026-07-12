#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      PlatformManager.h
 *
 * Description:
 *      Central platform management system.
 ******************************************************************************/

#include "PlatformInfo.h"
#include "PlatformProviders.h"

class PlatformManager {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	PlatformManager();

	~PlatformManager();

	// -------------------------------------------------------------------------
	// Lifecycle
	// -------------------------------------------------------------------------

	void Initialize();

	void Shutdown();

	// -------------------------------------------------------------------------
	// Providers
	// -------------------------------------------------------------------------

	void SetTimeProvider(
			ITimeProvider *provider);

	void SetFileProvider(
			IFileProvider *provider);

	[[nodiscard]]
	ITimeProvider *GetTimeProvider() const;

	[[nodiscard]]
	IFileProvider *GetFileProvider() const;

	// -------------------------------------------------------------------------
	// Information
	// -------------------------------------------------------------------------

	[[nodiscard]]
	bool IsInitialized() const;

	[[nodiscard]]
	const PlatformInfo &GetPlatformInfo() const;

private:
	PlatformInfo m_platformInfo;

	ITimeProvider *m_timeProvider = nullptr;

	IFileProvider *m_fileProvider = nullptr;

	bool m_initialized = false;
};
