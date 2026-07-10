# ADR-0001

# Introduce IModule

## Status

Accepted

## Date

Aurora v0.6

---

## Context

Aurora originally managed engine systems directly from AuroraCore.

As the engine grew, this approach increased coupling between systems and
made future expansion more difficult.

A common interface was required to manage every engine subsystem through
the same lifecycle.

---

## Decision

Introduce a common interface named `IModule`.

Every engine subsystem must implement this interface.

Each module exposes the following lifecycle:

- Initialize()
- Update()
- Shutdown()

Each module also provides metadata:

- GetName()
- GetVersion()
- GetState()
- IsInitialized()

---

## Consequences

Positive

- Unified module lifecycle
- Easy module registration
- Simplified engine startup
- Future plugin support
- Easier AI integration

Negative

- Small abstraction overhead

---

## Alternatives Considered

Direct subsystem initialization inside AuroraCore.

Rejected because it tightly couples the engine.

---

## Related Documents

LayeredArchitecture.md

ModuleStandard.md

ArchitectureRules.md

---

## Notes

This ADR establishes the foundation of Aurora's modular architecture.
