# Module System

## Overview

Aurora uses a modular architecture.

Every major engine feature should be implemented as an independent module.

The engine core only coordinates modules.

Modules contain the actual functionality.

---

# Goals

- Loose coupling
- Easy extensibility
- Independent systems
- Clear initialization order

---

# Architecture

```
AuroraModuleManager

↓

IAuroraModule

↓

Initialize()

↓

Update()

↓

Shutdown()
```

---

# Module Lifecycle

Every module follows the same lifecycle.

```
Register

↓

Initialize

↓

Update

↓

Shutdown

↓

Destroy
```

---

# Responsibilities

AuroraModuleManager is responsible for:

- Registering modules
- Initializing modules
- Updating modules
- Shutting down modules
- Preventing duplicate registration

---

# IAuroraModule

Every engine module implements:

```
Initialize()

Update()

Shutdown()
```

This guarantees a consistent lifecycle across the engine.

---

# Current Modules

- AuroraTestModule

Future modules include:

- Renderer
- Physics
- Audio
- Input
- Scene
- ECS
- AI
- Networking

---

# Design Principles

Modules should never directly depend on one another.

Communication should happen through:

- Events
- Engine services
- Shared interfaces

---

# Status

Stable

---

# Since Version

v0.1.0 Foundation

---

# Related Documents

- Core
- Platform
- Event System
