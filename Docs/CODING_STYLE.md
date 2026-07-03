# Aurora Engine Coding Style

Version: 1.0

---

# General Principles

- Write readable code first.
- Prefer simplicity over cleverness.
- Every system should have a single responsibility.
- Keep functions small.
- Avoid global state whenever possible.

---

# Naming Convention

## Classes

Use PascalCase.

```cpp
class AuroraCore;
class EventBus;
class EntityManager;
```

---

## Functions

Use PascalCase.

```cpp
Initialize();
Shutdown();
RegisterModule();
Publish();
```

---

## Variables

Member variables use `m_`.

```cpp
m_initialized
m_running
m_modules
```

Local variables use camelCase.

```cpp
listener
event
component
entity
```

---

## Constants

Use PascalCase.

```cpp
constexpr int MaxEntities = 10000;
```

---

## Files

One class per file.

Example:

```
Entity.h
Entity.cpp

EventBus.h
EventBus.cpp
```

---

# Header Order

```cpp
// Aurora headers

// Third-party headers

// STL headers
```

Example:

```cpp
#include "../include/AuroraCore.h"

#include <memory>
#include <vector>
```

---

# Function Layout

```cpp
bool AuroraCore::Initialize()
{
    if (m_initialized)
    {
        return true;
    }

    ...

    return true;
}
```

Always use braces.

Avoid one-line if statements.

---

# Comment Standard

## TODO

Future improvement.

```cpp
// TODO(v0.3)
// Move EventBus logs to Debug level.
```

---

## FIXME

Known issue.

```cpp
// FIXME
// Current implementation is not thread-safe.
```

---

## NOTE

Important information.

```cpp
// NOTE
// Shutdown order is reverse initialization order.
```

---

## REVIEW

Needs future evaluation.

```cpp
// REVIEW
// Evaluate lock-free queue.
```

---

## OPTIMIZE

Performance improvement.

```cpp
// OPTIMIZE
// Reduce allocations.
```

---

## DEPRECATED

Legacy code.

```cpp
// DEPRECATED(v0.5)
// Remove after ECS migration.
```

---

# Logging

Allowed log levels:

- Success
- Info
- Warning
- Error

Future versions:

- Debug
- Trace

---

# Documentation

Every subsystem must have documentation inside:

docs/ARCHITECTURE/

Example:

Core.md

EventSystem.md

Renderer.md

Physics.md

AI.md

Networking.md

---

# Git Commit Format

Examples:

feat(core): initialize engine core

feat(events): implement event bus

fix(events): publish EngineStarted only once

docs: update architecture

refactor(core): simplify initialization

---

# Pull Request Rule

Every major feature must include:

- Documentation update
- Changelog update
- Successful build

---

Aurora Engine Coding Style v1.0

## Include Style

Always include headers using the project include path.

✔ Good

```cpp
#include "AuroraLogger.h"
#include "ecs/Registry.h"
#include "events/EventBus.h"
