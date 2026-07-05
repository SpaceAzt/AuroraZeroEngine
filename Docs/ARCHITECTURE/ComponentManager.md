# ComponentManager

## Overview

`ComponentManager` is responsible for managing every component storage used by the ECS.

Instead of letting `Registry` directly own all component storages, the responsibility is delegated to `ComponentManager`.

This improves separation of concerns and keeps `Registry` focused on entity lifetime.

---

## Responsibilities

- Register component storages
- Retrieve component storages
- Prevent duplicate storage registration
- Remove all components belonging to an entity
- Provide storage statistics

---

## Public API

### RegisterStorage<Component>()

Registers a storage for a component type.

If the storage already exists, the request is ignored.

---

### HasStorage<Component>()

Checks whether a storage has already been registered.

Returns:

- true
- false

---

### GetStorage<Component>()

Returns the storage associated with a component type.

Returns:

- ComponentStorage<Component>*
- nullptr if not registered

---

### RemoveEntity()

Removes every component owned by an entity.

Used internally by Registry::DestroyEntity().

---

### StorageCount()

Returns the total number of registered component storages.

---

## Internal Data Structure

std::unordered_map<
    std::type_index,
    std::unique_ptr<IComponentStorage>
>

The map key is the component type.

The value is the corresponding storage.

---

## Design Goals

- O(1) storage lookup
- One storage per component type
- Automatic lifetime management
- Registry remains lightweight
- Easy future reflection support

---

## Future Improvements

- Storage iteration
- Component reflection
- Runtime component registration
- Serialization support
