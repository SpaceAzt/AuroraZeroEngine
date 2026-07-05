# Registry

## Overview

`Registry` is the central ECS interface.

It manages entity lifetime while delegating component storage management to `ComponentManager`.

---

## Responsibilities

- Create entities
- Destroy entities
- Add components
- Remove components
- Access components
- Create ECS views
- Create multiviews

---

## Architecture

Registry

↓

ComponentManager

↓

ComponentStorage<T>

↓

SparseSet

---

## Entity Lifetime

### CreateEntity()

Creates a new entity identifier.

Returns:

Entity

---

### DestroyEntity()

Removes

- all owned components
- entity from the registry

Internally calls

ComponentManager::RemoveEntity()

---

## Component API

- AddComponent()
- RemoveComponent()
- HasComponent()
- GetComponent()

Component storage is automatically created when needed.

---

## Views

Registry supports

- View<T>
- MultiView<T...>

for efficient iteration.

---

## Design Goals

- Lightweight interface
- Automatic storage creation
- Clear ownership rules
- Fast lookup
- Minimal runtime overhead
