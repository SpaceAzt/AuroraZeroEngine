# ADR-0003

# Introduce EngineContext

## Status

Accepted

## Date

Aurora v0.6

---

## Context

Multiple systems required shared runtime information.

Passing managers individually would create unnecessary dependencies.

---

## Decision

Introduce EngineContext.

EngineContext contains:

- ModuleManager
- EngineState

Future versions may include:

- Configuration
- Project information
- Runtime services

---

## Consequences

Positive

- Shared runtime context
- Cleaner APIs
- Better scalability

Negative

- One additional abstraction layer

---

## Alternatives Considered

Passing managers directly.

Rejected because it increases coupling.

---

## Related Documents

LayeredArchitecture.md

AuroraCoreUML.md

---

## Notes

EngineContext is not a Service Locator.
