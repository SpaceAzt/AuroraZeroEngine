# Changelog

All notable changes to AuroraZeroEngine are documented here.

This project follows Semantic Versioning.



---

## v0.3.5

### Added

- ECS System interface (ISystem)
- SystemManager
- MovementSystem
- VelocityComponent
- System Manager tests

### Changed

- ECS now supports system registration and execution.
- Added update pipeline for ECS systems.

### Tested

- System registration
- System execution
- MovementSystem update

---

## v0.3.4

### Added

- ECS View<T>
- Registry::CreateView<T>()
- SparseSet iteration support
- ComponentStorage accessors
- ECS View tests

### Changed

- Registry now supports efficient component iteration.
- Improved ECS architecture for future systems.

### Tested

- View iteration
- Registry component iteration
- SparseSet integration

---

# v0.3.3 - Registry Component API

## Added

- Registry component management API
- `Registry::AddComponent<T>()`
- `Registry::RemoveComponent<T>()`
- `Registry::HasComponent<T>()`
- `Registry::GetComponent<T>()`
- Automatic component storage creation
- Runtime component validation

## Improved

- Registry now manages component storages using `std::type_index`.
- Added generic storage lookup through `GetStorage<T>()`.
- Improved component access safety using runtime checks.
- Cleaner template implementation and documentation.

## Tests

- Added Registry Component API integration test.
- Verified component creation, retrieval, update and removal.
- Validated interaction between Registry, ComponentStorage and SparseSet.

---

# v0.3.2 - Component Storage

## Added

- Generic `ComponentStorage<T>`
- Dense component array
- SparseSet integration
- Generic component access API

## Tests

- Component add/remove test
- Component retrieval test
- Storage cleanup validation

---

# v0.3.1 - Sparse Set

## Added

- SparseSet implementation
- Dense/Sparse indexing
- Constant-time insert/remove
- Constant-time lookup

## Tests

- Insert test
- Remove test
- Reinsert test
- Dense index validation

---

# v0.3.0 - ECS Foundation

## Added

- Entity
- Registry
- EntityManager
- ECS documentation
- Initial ECS architecture

## Tests

- Entity creation
- Entity destruction
- Registry validation

---

# v0.2.0 - Event System

## Added

- Core Event System
- EventBus
- EventDispatcher
- EngineStartedEvent
- EngineStoppedEvent
- Module event infrastructure
- AuroraTestModule event validation

---

# v0.1.0 - Foundation

## Added

- AuroraCore
- AuroraApplication
- AuroraPlatform
- AuroraModuleManager
- IAuroraModule
- AuroraLogger
- AuroraConfig
- AuroraVersion
- AuroraFileSystem
- AuroraTime
- Time Provider abstraction
- File Provider abstraction
- Godot integration
- Initial project documentation

## Changed

- Introduced layered engine architecture.
- Separated platform services from the engine core.
- Added provider-based abstraction.

## Fixed

- Module initialization validation.
- Duplicate module registration protection.
