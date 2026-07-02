# Aurora Core

## Overview

AuroraCore is the central coordinator of AuroraZeroEngine.

It is responsible for initializing, updating and shutting down the engine.

AuroraCore does not directly implement platform specific functionality.

Instead, it delegates responsibilities to dedicated subsystems.

---

# Responsibilities

AuroraCore is responsible for:

- Engine lifecycle
- Module initialization
- Module update
- Module shutdown
- Platform initialization
- Global engine state

AuroraCore should remain lightweight.

Business logic belongs inside modules.

---

# Lifecycle

The engine follows this lifecycle.

```
Initialize()

↓

Platform Initialize

↓

ModuleManager Initialize

↓

Engine Running

↓

Update()

↓

Module Updates

↓

Shutdown()

↓

Module Shutdown

↓

Platform Shutdown
```

---

# Architecture

```
AuroraApplication
        │
        ▼
AuroraCore
        │
 ┌──────┴────────┐
 ▼               ▼
AuroraPlatform   AuroraModuleManager
```

AuroraCore coordinates the engine but does not own platform specific implementations.

---
# Design Principles

The Core follows several principles.

## Single Responsibility

AuroraCore coordinates.

It does not render.

It does not process input.

It does not simulate physics.

Those responsibilities belong to dedicated systems.

---

## Platform Independence

Platform specific functionality is accessed through AuroraPlatform.

AuroraCore never communicates directly with operating system APIs.

---

## Modular Design

Every engine feature should be implemented as an independent module.

Modules communicate through shared engine services instead of tightly coupling to one another.

---

# Initialization Order

```
AuroraApplication

↓

AuroraCore

↓

AuroraPlatform

↓

AuroraModuleManager

↓

Registered Modules
```

Shutdown occurs in reverse order.

---

# Current State

Status

Stable

Version

v0.1.0 Foundation

---

# Future Improvements

- Event System
- Job System
- Engine Profiler
- Memory Manager
- Resource Manager
