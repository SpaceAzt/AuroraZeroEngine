# Platform Layer

## Overview

The Platform Layer provides an abstraction between AuroraCore and the underlying operating system or engine.

AuroraCore never directly communicates with platform-specific APIs.

Instead, all platform services are accessed through AuroraPlatform.

This architecture makes Aurora portable and maintainable.

---

# Responsibilities

AuroraPlatform is responsible for managing platform-dependent services.

Current providers include:

- Time Provider
- File Provider

Future providers may include:

- Window Provider
- Input Provider
- Audio Provider
- Thread Provider
- Network Provider
- Clipboard Provider
- Process Provider

---

# Architecture

```
AuroraCore
      │
      ▼
AuroraPlatform
      │
 ┌────┴──────────────┐
 ▼                   ▼
ITimeProvider    IFileProvider
```

The platform layer acts as a service locator for engine-wide providers.

---

# Provider Pattern

Aurora uses provider interfaces to separate implementation from usage.

Example:

```
AuroraTime

↓

AuroraPlatform

↓

ITimeProvider

↓

GodotTimeProvider
```

AuroraTime does not know which implementation is being used.

It only communicates with the interface.

---

# Advantages

- Platform independence
- Easy testing
- Easy replacement of implementations
- Clean engine architecture
- Better maintainability

---

# Current Providers

## Time Provider

Responsible for

- Delta Time
- Total Time
- Engine Timing

---

## File Provider

Responsible for

- File existence
- Directory creation
- File deletion

Future versions will support

- File reading
- File writing
- Virtual File System

---

# Future Providers

The Platform Layer will continue to grow.

Planned providers include:

- Input
- Window
- Audio
- Network
- Clipboard
- Thread
- Memory
- Process

---

# Status

Stable

---

# Since Version

v0.1.0 Foundation

---

# Related Documents

- Core
- Module System
- Event System
