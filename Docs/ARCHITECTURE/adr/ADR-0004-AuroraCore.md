# ADR-0004

# Simplify AuroraCore

## Status

Accepted

## Date

Aurora v0.6

---

## Context

AuroraCore originally controlled every subsystem directly.

This design would become increasingly difficult to maintain.

---

## Decision

AuroraCore only manages engine lifecycle.

Responsibilities:

- Initialize()
- Update()
- Shutdown()

AuroraCore communicates only with EngineContext.

---

## Consequences

Positive

- Small engine core
- Easier maintenance
- Better scalability

Negative

None

---

## Alternatives Considered

Continue expanding AuroraCore.

Rejected because it violates modularity.

---

## Related Documents

EngineContext.md

ModuleManager.md

---

## Notes

AuroraCore should remain small throughout the project's lifetime.
