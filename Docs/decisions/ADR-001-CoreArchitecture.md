# ADR-001: Layered Core Architecture

## Status

Accepted

---

## Date

2026-07-02

---

## Context

AuroraZeroEngine requires a clean, scalable and maintainable architecture.

The engine must support multiple systems such as rendering, physics, AI, networking and editor tools without creating tight coupling.

---

## Decision

AuroraZeroEngine adopts a layered architecture.

```
AuroraApplication
        │
        ▼
AuroraCore
        │
 ┌──────┴────────┐
 ▼               ▼
AuroraPlatform   AuroraModuleManager
        │
        ▼
Providers
```

AuroraCore coordinates the engine.

Subsystems are implemented as modules.

Platform-specific functionality is accessed through provider interfaces.

---

## Consequences

### Advantages

- Clean separation of responsibilities
- Platform independence
- Easier testing
- Easier maintenance
- Better scalability

### Disadvantages

- Slightly more abstraction
- More initial setup
- Additional interfaces

---

## Alternatives Considered

### Monolithic Engine

Rejected because it creates tight coupling.

### Static Global Systems

Rejected because testing and replacement become difficult.

---

## Related Documents

- Core
- Platform
- Module System
