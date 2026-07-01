#pragma once

class ITimeProvider;

class AuroraPlatform {
public:
	static void Initialize();

	static void Shutdown();

	static void SetTimeProvider(ITimeProvider *provider);

	static ITimeProvider *GetTimeProvider();

private:
	static ITimeProvider *s_timeProvider;
};
