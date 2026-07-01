#pragma once

#include <memory>
#include <vector>

class IAuroraModule;

class AuroraModuleManager {
public:
	static void Initialize();

	static void Update();

	static void Shutdown();

	static void RegisterModule(std::shared_ptr<IAuroraModule> module);

private:
	static std::vector<std::shared_ptr<IAuroraModule>> m_modules;
};
