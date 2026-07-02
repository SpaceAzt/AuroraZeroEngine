# Event System

## Overview

The Event System provides communication between independent engine systems.

Instead of directly calling one another, systems exchange events through a central Event Bus.

This design reduces coupling and improves modularity.

---

# Goals

The Event System is designed to provide:

- Loose coupling
- High performance
- Simple API
- Easy debugging
- Thread-safe future expansion

---

# Architecture

```
Window

↓

WindowResizeEvent

↓

EventDispatcher

↓

EventBus

↓

Subscribers

↓

Renderer
UI
Editor
```

---

# Event Flow

The event lifecycle follows these steps.

```
Create Event

↓

Dispatch Event

↓

Event Bus

↓

Event Listener

↓

Handle Event
```

---

# Core Components

## IEvent

Base interface for every event.

Responsibilities

- Event type
- Event category
- Event name

---

## EventDispatcher

Responsible for delivering an event to the correct listeners.

Only dispatches events.

Does not store them.

---

## EventBus

Central communication hub.

Responsibilities

- Register listeners
- Remove listeners
- Broadcast events

---

## EventListener

Receives specific event types.

A listener subscribes only to the events it needs.

---

# Planned Events

## Window

- WindowCreated
- WindowClosed
- WindowResized
- WindowMoved

---

## Input

- KeyPressed
- KeyReleased
- MouseMoved
- MouseButtonPressed
- MouseWheel

---

## Engine

- EngineStarted
- EngineStopped
- ModuleLoaded
- ModuleUnloaded

---

## Renderer

- RenderStarted
- RenderFinished
- ShaderReloaded

---

## Physics

- CollisionEnter
- CollisionExit

---

# Event Categories

Every event belongs to one or more categories.

Examples

- Window
- Input
- Renderer
- Physics
- Engine
- UI
- Editor
- Network

---

# Design Principles

The Event System follows these principles.

## No direct dependencies

Systems never call each other directly.

---

## Fast dispatch

Dispatching should be lightweight.

---

## Extensible

Adding new events should not require modifying existing code.

---

## Maintainable

Each event has a single responsibility.

---

# Future Improvements

- Event priorities
- Asynchronous events
- Thread-safe event queue
- Delayed events
- Event recording
- Event replay

---

# Status

Planned

---

# Target Version

v0.2.0 Event System

---

# Related Documents

- Core
- Platform
- Module System
