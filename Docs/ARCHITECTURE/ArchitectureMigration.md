# Aurora Engine
## Architecture Migration Guide

---

## Purpose

This document tracks Aurora's transition from the legacy engine
architecture to the new modular engine architecture.

The migration is incremental.

Each subsystem is modernized independently to keep the engine
stable throughout development.

---

## Current Progress

| Legacy System | Modular System | Status |
|--------------|----------------|--------|
| AuroraModuleManager | ModuleManager | ✅ Completed |
| Memory System | MemoryModule | ✅ Completed |
| Engine Context | EngineContext | ✅ Completed |
| AuroraCore | New AuroraCore | 🔄 In Progress |
| EventBus | EventModule | 📋 Planned |
| AuroraTime | TimeModule | 📋 Planned |
| AuroraPlatform | PlatformModule | 📋 Planned |
| AuroraLogger | LoggingModule | 📋 Planned |
| AuroraFileSystem | FileSystemModule | 📋 Planned |
| Renderer | RendererModule | 📋 Planned |
| Physics | PhysicsModule | 📋 Planned |
| ECS | ECSModule | 📋 Planned |
| Sentinel | SentinelModule | 📋 Planned |

---

## Migration Principles

1. Never break the engine.

2. Refactor incrementally.

3. Every subsystem becomes a module.

4. AuroraCore remains minimal.

5. New systems never depend on legacy systems.

6. Tests must pass after every migration.

7. Documentation is updated together with the code.

---

## Completed Milestones

### Aurora v0.5

- Memory Allocators
- Memory Manager
- Pool Allocator
- Arena Allocator
- Stack Allocator
- Linear Allocator

---

### Aurora v0.6

- EngineState
- IModule
- ModuleManager
- EngineContext
- MemoryModule
- Layered Architecture
- Engineering Standards

---

## Future Migration

Aurora v0.7

- Event Module
- Event Bus
- Job System
- Thread System

Aurora v0.8

- Reflection
- Serialization
- Resource System

Aurora v1.0

- Renderer
- ECS
- Physics
- Audio
- Scene System

Aurora v2.0

- Sentinel AI
- Native Backend
- Godot Backend
