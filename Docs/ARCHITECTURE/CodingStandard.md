Aurora Coding Standard

✓ Header (.h)

- Template sınıflar
- Template fonksiyonlar
- Inline fonksiyonlar

✓ Source (.cpp)

- Constructor
- Destructor
- Normal fonksiyonlar
- Karmaşık algoritmalar

# Aurora Engine Coding Standard

Version: v0.7

---

# Philosophy

Aurora is designed for:

- Performance
- Readability
- Maintainability
- Scalability

Performance is important.

Maintainability is equally important.

Optimize only where measurements show it is necessary.

---

# Performance Categories

Aurora code is divided into three categories.

## Hot Path

Performance critical.

Examples:

- ECS
- Renderer
- Physics
- Memory
- Math
- SIMD
- Animation
- Job System

Rules

✔ inline allowed

✔ constexpr encouraged

✔ templates encouraged

✔ header-only utilities allowed

✔ avoid virtual calls

✔ avoid heap allocation

---

## Warm Path

Balanced.

Examples

- Resource System
- Platform
- Serialization
- Reflection
- Audio

Rules

Prefer clean architecture.

Optimize only after profiling.

---

## Cold Path

Readability first.

Examples

- Logging
- Editor
- Tools
- Importers
- Console
- Debug UI

Rules

Prefer .cpp implementation.

Prefer readability.

Avoid premature optimization.

---

# Header Files

Headers should contain:

- class
- struct
- enum
- template
- constexpr
- inline
- declarations

Avoid implementing large algorithms.

---

# Source Files

Source files should contain:

- implementations
- algorithms
- platform code
- resource loading
- logging
- networking
- editor code

---

# Inline Policy

Good

inline bool IsRunning() const;

constexpr std::size_t Capacity() const;

Bad

inline RenderFrame()

inline LoadScene()

---

# Constexpr Policy

Use constexpr whenever possible.

Examples

- constants
- compile-time lookup
- math utilities
- enum conversions

---

# Virtual Functions

Allowed for:

- interfaces

Examples

IModule

ILogger

IAllocator

ITimeProvider

Avoid virtual functions inside hot loops.

---

# Memory Allocation

Avoid dynamic allocation inside:

- Update()
- Render()
- Physics
- ECS

Allocate during initialization whenever possible.

---

# Logging

Logging is considered Cold Path.

Never optimize logging before profiling.

---

# Documentation

Every module contains:

include/

src/

docs/

tests/

benchmarks/

SCsub

---

# Testing

Every module has its own tests.

Every new feature should have tests.

---

# ADR

Major architectural decisions must be documented as ADRs.

---

# Principle

Clean code first.

Measured optimization second.

Premature optimization never.


Engine code never writes directly
to std::cout.

Engine code never calls printf.

Engine code always uses LogManager.


# Ownership Policy

Use std::unique_ptr when:

- a class owns a single object
- ownership is exclusive

Use std::shared_ptr only when:

- ownership is shared

Use raw pointers only when:

- the object is not owned
- observing only

Avoid new/delete in engine code.
Prefer RAII.


## SCsub Rules

Every module owns its own SCsub.

Paths inside a module SCsub are always relative.

Correct:

    src/*.cpp

Incorrect:

    logging/src/*.cpp
