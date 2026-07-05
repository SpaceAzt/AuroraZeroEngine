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

#include <vector>
#include <stdexcept>

#include "ecs/storage/ComponentStorage.h"
#include "ecs/storage/IComponentStorage.h"
#include "ecs/view/View.h"
#include "ecs/view/MultiView.h"
#include "ecs/ComponentManager.h"


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

	template <typename T>
	const ComponentStorage<T> *GetStorage() const;

	// -------------------------------------------------------------------------
	// Managers
	// -------------------------------------------------------------------------

	ComponentManager &GetComponentManager();

	const ComponentManager &GetComponentManager() const;

private:

	// -------------------------------------------------------------------------
	// Storage Access
	// -------------------------------------------------------------------------

	template <typename T>
	ComponentStorage<T> *GetStorage();

	// -------------------------------------------------------------------------
	// Managers
	// -------------------------------------------------------------------------

	ComponentManager m_componentManager;

	// -------------------------------------------------------------------------
	// Entity Storage
	// -------------------------------------------------------------------------

	Entity::Id m_nextEntityId = 1;

	std::vector<Entity> m_entities;
};


// -----------------------------------------------------------------------------
// Get Storage
// -----------------------------------------------------------------------------

template <typename T>
ComponentStorage<T> *Registry::GetStorage() {
	if (!m_componentManager.HasStorage<T>()) {
		m_componentManager.RegisterStorage<T>();
	}

	return m_componentManager.GetStorage<T>();
}

// -----------------------------------------------------------------------------
// Get Storage (Const)
// -----------------------------------------------------------------------------

template <typename T>
const ComponentStorage<T> *Registry::GetStorage() const {
	if (!m_componentManager.HasStorage<T>()) {
		return nullptr;
	}

	return m_componentManager.GetStorage<T>();
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
	const auto *storage = GetStorage<T>();

	if (storage == nullptr) {
		return false;
	}

	return storage->Has(entity.GetId());
}

// -----------------------------------------------------------------------------
// GetComponent (Const)
// -----------------------------------------------------------------------------

template <typename T>
const T &Registry::GetComponent(Entity entity) const {
	const auto *storage = GetStorage<T>();

	if (storage == nullptr || !storage->Has(entity.GetId())) {
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

