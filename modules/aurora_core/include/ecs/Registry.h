#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      Registry.h
 *
 * Description:
 *      Central ECS registry.
 *      Responsible for entity creation and lifetime.
 ******************************************************************************/

#include "Entity.h"

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <stdexcept>

#include "ecs/storage/ComponentStorage.h"
#include "ecs/storage/IComponentStorage.h"
#include "ecs/view/View.h"
#include "ecs/view/MultiView.h"


class Registry {
public:
	// -------------------------------------------------------------------------
	// Lifetime
	// -------------------------------------------------------------------------

	Registry();

	// -------------------------------------------------------------------------
	// Entity
	// -------------------------------------------------------------------------

	Entity CreateEntity();

	void DestroyEntity(Entity entity);

	bool IsAlive(Entity entity) const;

	// -------------------------------------------------------------------------
	// Components
	// -------------------------------------------------------------------------

	template <typename T>
	void AddComponent(Entity entity, const T &component);

	template <typename T>
	void RemoveComponent(Entity entity);

	template <typename T>
	bool HasComponent(Entity entity) const;

	template <typename T>
	T &GetComponent(Entity entity);

	template <typename T>
	const T &GetComponent(Entity entity) const;

	template <typename T>
	View<T> CreateView();

	template <typename... Components>
	MultiView<Components...> CreateMultiView();

private:

	// -------------------------------------------------------------------------
	// Storage Access
	// ------------------------------------------------------------------------

	 template <typename T>
	ComponentStorage<T> *GetStorage();

	
	 // ------------------------------------------------------------------------
	 // TODO(v0.4):
	 // Implement ECS Views and Queries for efficient component iteration.
     // ------------------------------------------------------------------------

	 Entity::Id m_nextEntityId = 1;

	 std::vector<Entity> m_entities;

	 std::unordered_map<
			 std::type_index,
			 std::unique_ptr<IComponentStorage>>
			 m_componentStorages;
};

// -----------------------------------------------------------------------------
// GetStorage
//
// Returns the storage for component type T.
// Creates it on first use.
// -----------------------------------------------------------------------------

template <typename T>
ComponentStorage<T> *Registry::GetStorage() {
	const std::type_index type(typeid(T));

	auto it = m_componentStorages.find(type);

	if (it == m_componentStorages.end()) {
		auto storage = std::make_unique<ComponentStorage<T>>();

		ComponentStorage<T>* ptr = storage.get();

		m_componentStorages.emplace(type, std::move(storage));

		return ptr;
	}

	return static_cast<ComponentStorage<T>* >(it->second.get());
}

// -----------------------------------------------------------------------------
// AddComponent
// -----------------------------------------------------------------------------

template <typename T>
void Registry::AddComponent(Entity entity, const T &component) {
	GetStorage<T>()->Add(entity.GetId(), component);
}
// -----------------------------------------------------------------------------
// RemoveComponent
// -----------------------------------------------------------------------------

template <typename T>
void Registry::RemoveComponent(Entity entity) {
	GetStorage<T>()->Remove(entity.GetId());
}
// -----------------------------------------------------------------------------
// HasComponent
// -----------------------------------------------------------------------------

template <typename T>
bool Registry::HasComponent(Entity entity) const {
	const std::type_index type(typeid(T));

	auto it = m_componentStorages.find(type);

	if (it == m_componentStorages.end()) {
		return false;
	}

	auto* storage =
			static_cast<ComponentStorage<T> *>(it->second.get());

	return storage->Has(entity.GetId());
}

// -----------------------------------------------------------------------------
// GetComponent (const)
// -----------------------------------------------------------------------------

template <typename T>
const T &Registry::GetComponent(Entity entity) const {
	const std::type_index type(typeid(T));

	auto it = m_componentStorages.find(type);

	if (it == m_componentStorages.end()) {
		throw std::runtime_error("Component storage not found.");
	}

	auto *storage =
			static_cast<ComponentStorage<T>* >(it->second.get());

	if (!storage->Has(entity.GetId())) {
		throw std::runtime_error(
				"Entity does not have requested component.");
	}

	return storage->Get(entity.GetId());
}

// -----------------------------------------------------------------------------
// GetComponent
// -----------------------------------------------------------------------------

template <typename T>
T &Registry::GetComponent(Entity entity) {
	if (!HasComponent<T>(entity)) {
		throw std::runtime_error(
				"Entity does not have requested component.");
	}

	return GetStorage<T>()->Get(entity.GetId());
}

// -----------------------------------------------------------------------------
// CreateView
// -----------------------------------------------------------------------------

template <typename T>
View<T> Registry::CreateView() {
	return View<T>(GetStorage<T>());
}

// -----------------------------------------------------------------------------
// CreateMultiView
// -----------------------------------------------------------------------------

template <typename... Components>
MultiView<Components...> Registry::CreateMultiView() {
	return MultiView<Components...>(
			GetStorage<Components>()...);
}
