# ADR-002: Platform Provider Abstraction

## Status

Accepted

---

## Date

2026-07-02

---

## Context

Aurora should not directly depend on operating system APIs or external engine APIs.

---

## Decision

Platform services are accessed through provider interfaces.

Examples:

- ITimeProvider
- IFileProvider

Future providers:

- Input
- Window
- Audio
- Network
- Clipboard

---

## Motivation

Provider interfaces allow different implementations without changing engine code.

Examples:

GodotTimeProvider

SDLTimeProvider

WindowsTimeProvider

LinuxTimeProvider

---

## Benefits

- Portability
- Extensibility
- Cleaner architecture
- Easier testing

---

## Related Documents

- Platform
- Core
