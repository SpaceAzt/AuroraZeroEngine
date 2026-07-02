#pragma once

class AuroraCore {
public:
	static AuroraCore &Get();

	bool Initialize();

	void Update();

	void Shutdown();

	bool IsRunning() const;

	void Stop();

private:
	AuroraCore();

	~AuroraCore();

	AuroraCore(const AuroraCore &) = delete;
	AuroraCore &operator=(const AuroraCore &) = delete;

private:
	bool m_initialized = false;
	bool m_running = false;
};
