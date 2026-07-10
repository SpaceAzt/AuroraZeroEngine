# ADR-0005

# Standardize Module Structure

## Status

Accepted

## Date

Aurora v0.6

---

## Context

Every engine subsystem requires a consistent layout.

Without standards, project organization becomes inconsistent over time.

---

## Decision

Every module follows the same directory layout.

include/

private/

src/

tests/

benchmarks/

docs/

Every module owns:

- Implementation
- Tests
- Documentation
- Benchmarks

---

## Consequences

Positive

- Consistent project structure
- Easier onboarding
- Better maintainability

Negative

Slightly larger directory structure

---

## Alternatives Considered

Centralized tests and documentation.

Rejected because modules should remain self-contained.

---

## Related Documents

ModuleStandard.md

TestStandard.md

---

## Notes

This standard applies to every Aurora module.
