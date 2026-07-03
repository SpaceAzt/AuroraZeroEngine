# Component Storage

## Purpose

Stores all components of a single type.

Example:

ComponentStorage<TransformComponent>

ComponentStorage<MeshComponent>

ComponentStorage<CameraComponent>

---

## Responsibilities

- Add components
- Remove components
- Lookup components
- Clear storage

---

## Internal Structure

Registry

↓

ComponentStorage<T>

↓

SparseSet

↓

Dense Arrays

## Data Layout

Dense Entities

```
1
5
10
```

↓

Dense Components

```
Transform
Transform
Transform
```

Both arrays always share the same index.
