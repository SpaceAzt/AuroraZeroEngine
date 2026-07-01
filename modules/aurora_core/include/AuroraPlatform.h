#pragma once

class ITimeProvider;
class IFileProvider;

class AuroraPlatform {
public:
	static void Initialize();

	static void Shutdown();

	static void SetTimeProvider(ITimeProvider *provider);
	static ITimeProvider *GetTimeProvider();

	static void SetFileProvider(IFileProvider *provider);
	static IFileProvider *GetFileProvider();

private:
	static ITimeProvider *s_timeProvider;
	static IFileProvider *s_fileProvider;
};
