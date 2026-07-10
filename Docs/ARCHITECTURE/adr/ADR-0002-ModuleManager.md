# ADR-0002

# Introduce ModuleManager

## Status

Accepted

## Date

Aurora v0.6

---

## Context

AuroraCore previously initialized engine systems directly.

As more modules were planned, a dedicated lifecycle manager became
necessary.

---

## Decision

Introduce ModuleManager.

Responsibilities:

- Register modules
- Unregister modules
- Initialize modules
- Update modules
- Shutdown modules

ModuleManager never owns modules.

---

## Consequences

Positive

- Loose coupling
- Centralized lifecycle
- Plugin-ready architecture
- Cleaner AuroraCore

Negative

- Slightly more abstraction

---

## Alternatives Considered

AuroraCore managing all modules.

Rejected because AuroraCore would continuously grow.

---

## Related Documents

IModule.md

LayeredArchitecture.md

---

## Notes

Ownership remains outside ModuleManager.
