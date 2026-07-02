# Entity

Entity is only an identifier.

It does not contain data or behavior.

Example:

Player
Enemy
Camera

---

# Component

Components only store data.

They never contain game logic.

Examples

TransformComponent

CameraComponent

MeshComponent

LightComponent

## Registry

Registry manages all entities.

Responsibilities

- Create entities
- Destroy entities
- Validate entities

Future responsibilities

- Component storage
- System queries
- Entity iteration

## System

Systems contain game logic.

Systems process entities and components.

Examples

- MovementSystem
- RenderSystem
- PhysicsSystem
- AudioSystem
- AnimationSystem

## EntityManager

EntityManager provides a simplified interface for creating and destroying entities.

It delegates all operations to the Registry.

Future responsibilities:

- Entity naming
- Entity tags
- Prefab creation


