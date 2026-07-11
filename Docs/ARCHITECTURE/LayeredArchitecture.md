# Aurora Engine

# Layered Architecture

Version

v0.6

Status

Draft

---

# Overview

Aurora Engine follows a layered architecture.

Every module belongs to exactly one layer.

Upper layers may depend on lower layers.

Lower layers must never depend on upper layers.

```
Layer 6
Editor
Game
Tools

↓

Layer 5
Aurora Sentinel

↓

Layer 4
Renderer
Physics
Audio

↓

Layer 3
Scene
Resource
ECS

↓

Layer 2
Memory
Events
Thread
Reflection
Serialization

↓

Layer 1
Core

↓

Layer 0
Foundation
```

---

# Layer 0

Foundation

Purpose

Lowest level utilities.

Contains no engine logic.

Examples

- Types
- Platform
- Compiler
- Config
- Version
- Macros
- Assertions

Dependencies

None

---

# Layer 1

Core

Purpose

Engine initialization.

Application lifecycle.

Manager ownership.

Examples

- AuroraCore
- ModuleManager
- Logger
- FileSystem

Dependencies

Foundation

---

# Layer 2

Systems

Purpose

Reusable engine infrastructure.

Examples

- Memory
- EventBus
- Thread
- Reflection
- Serialization

Dependencies

Foundation

Core

---

# Layer 3

Gameplay Infrastructure

Purpose

Runtime engine systems.

Examples

- ECS
- Scene
- Resource

Dependencies

Foundation

Core

Systems

---

# Layer 4

Runtime Modules

Purpose

High level runtime features.

Examples

- Renderer
- Physics
- Audio

Dependencies

All lower layers

---

# Layer 5

Aurora Sentinel

Purpose

Observe.

Analyze.

Suggest.

Never own engine systems.

Responsibilities

- Diagnostics
- Reports
- Performance
- Memory Analysis
- Documentation
- Testing
- Build Analysis

Dependencies

All lower layers

Must never be required by lower layers.

---

# Layer 6

Applications

Purpose

Editor

Game

External Tools

Dependencies

All lower layers.

---

# Dependency Rules

Allowed

Layer 4

↓

Layer 3

↓

Layer 2

↓

Layer 1

↓

Layer 0

Forbidden

Layer 2

↓

Layer 4

Layer 0

↓

Layer 3

Layer 1

↓

Layer 5

---

# Aurora Sentinel

Sentinel is not the owner of the engine.

Sentinel observes the engine.

Sentinel analyzes the engine.

Sentinel suggests improvements.

Human approval is required before source code modifications.

---

# Design Principles

- Modular
- Test Driven
- Documentation First
- Dependency Injection
- Memory Managed
- Event Driven
- AI Assisted
- Platform Independent

---

# Future

v0.7

AuroraCore

v0.8

Sentinel Foundation

v1.0

Editor

v2.0

Multi-Agent Sentinel

                   Aurora Engine UML (v0.6)

                    +----------------------+
                    |     Application      |
                    +----------------------+
                              |
                              |
                              v
                    +----------------------+
                    |     AuroraCore       |
                    +----------------------+
                    | +Initialize()        |
                    | +Update()            |
                    | +Shutdown()          |
                    | +Run()               |
                    | +GetMemoryManager()  |
                    | +GetEventBus()       |
                    | +GetModuleManager()  |
                    +----------+-----------+
                               |
        -----------------------------------------------------
        |          |             |            |             |
        v          v             v            v             v
+--------------+ +-----------+ +-----------+ +---------+ +-----------+
|MemoryManager | | EventBus  | |ModuleMgr  | | Logger  | | Sentinel* |
+--------------+ +-----------+ +-----------+ +---------+ +-----------+


                         Aurora v1.0 UML


                         AuroraCore
                              |
     ---------------------------------------------------------
     |       |       |       |       |        |        |
     v       v       v       v       v        v        v
 Memory   Events   ECS   Renderer Physics  Audio  Resource
     |                                       |
     |                                       |
     -----------------------------           |
                           |                 |
                           v                 |
                      Aurora Sentinel <-------


AuroraCore'un Görevi

Bence sadece bunları yapmalı.

AuroraCore

↓

Initialize Engine

↓

Initialize Managers

↓

Initialize Modules

↓

Update Modules

↓

Shutdown Modules




Application
        │
        ▼
   AuroraCore
        │
        ▼
  ModuleManager
        │
        ├── Memory
        ├── ECS
        ├── Renderer
        ├── Physics
        ├── Audio
        ├── Resource
        ├── Scene
        └── Sentinel



		Application Layer
        │
        ▼
AuroraCore
        │
        ▼
EngineContext
        │
        ▼
ModuleManager
        │
        ▼
IModule
        │
─────────────────────────────
MemoryModule
LoggingModule
PlatformModule
TimeModule
EventModule
PhysicsModule
RendererModule
AI Module

Legacy Compatibility Layer

AuroraPlatform

AuroraLogger

AuroraTime

Godot Providers
