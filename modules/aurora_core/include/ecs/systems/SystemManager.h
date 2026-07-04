#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      SystemManager.h
 *
 * Description:
 *      Stores and updates ECS systems.
 ******************************************************************************/

#include <memory>
#include <vector>

class Registry;
class ISystem;

class SystemManager {
public:
	SystemManager() = default;

	void AddSystem(std::unique_ptr<ISystem> system);

	void Update(
			Registry &registry,
			float deltaTime);

private:
	std::vector<std::unique_ptr<ISystem>> m_systems;
};
