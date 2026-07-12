# Aurora Engine Module Development Guide

## Purpose

This document defines the standard architecture used by every Aurora Engine
module.

Following these conventions keeps the engine modular, maintainable and
consistent.

---

# Standard Module Layout

module/
├── benchmarks/
├── docs/
├── include/
├── private/
├── src/
├── tests/
└── SCsub

---

# Module Architecture

Module
    │
    ▼
Manager
    │
    ▼
Data Objects

Example:

LoggingModule
    ↓
LogManager
    ↓
LogMessage

MemoryModule
    ↓
MemoryManager
    ↓
MemoryStats

TimeModule
    ↓
TimeManager
    ↓
TimeSnapshot

---

# Responsibilities

Module

- Initialize
- Update
- Shutdown
- Own managers

Manager

- Engine logic
- Resource ownership
- State management

Data Objects

- Snapshot
- Stats
- Info
- Descriptor

Must not contain business logic.

---

# SCsub Rules

Each module owns its own SCsub.

Use relative paths only.

Correct:

src/*.cpp

Incorrect:

logging/src/*.cpp

---

# Lifetime

Created

↓

Registered

↓

Initializing

↓

Running

↓

ShuttingDown

↓

Stopped

---

# Naming

LoggingModule

LogManager

LogMessage

ConsoleLogger

MemoryModule

MemoryManager

MemoryStats

TimeModule

TimeManager

TimeSnapshot

---

# Memory Ownership

Prefer RAII.

Prefer std::unique_ptr.

Avoid manual delete.

---

# Coding Style

Use explicit constructors.

Use [[nodiscard]] where appropriate.

Prefer defaulted constructors/destructors.

Prefer const correctness.

Use clear section separators.

---

# Future Modules

Platform

Events

Resources

Input

Renderer

Physics

Audio

Networking

AI

All modules must follow this guide.


# Ownership Rule

A module owns every object it creates.

Managers never own platform implementations or providers.

Managers only access interfaces.

Ownership must be explicit.

Prefer RAII and std::unique_ptr.

Example:

LoggingModule
    owns
        ConsoleLogger

LogManager
    observes
        ILogger*

PlatformModule
    owns
        GodotTimeProvider
        GodotFileProvider

PlatformManager
    observes
        ITimeProvider*
        IFileProvider*

TimeModule
    owns
        TimeManager

MemoryModule
    owns
        MemoryManager
