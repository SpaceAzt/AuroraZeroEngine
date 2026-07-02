# Renderer

## Overview

The Renderer is responsible for drawing everything visible on screen.

AuroraRenderer will remain independent from the game logic.

Rendering should only consume scene data.

---

# Goals

- High performance
- Modern graphics API
- Multi-thread friendly
- Modular pipeline

---

# Planned APIs

- Vulkan
- DirectX 12 (future)
- Metal (future)
- OpenGL (debug only)

---

# Planned Components

- Render Device
- Render Context
- Render Graph
- Render Pipeline
- Shader Manager
- Material System
- Mesh System
- Texture System

---

# Rendering Flow

```
Scene

↓

Renderer

↓

Render Graph

↓

Render Pipeline

↓

GPU
```

---

# Future Features

- Deferred Rendering
- Forward+
- Shadow Mapping
- PBR
- HDR
- Post Processing
- GPU Culling
- Compute Pipeline

---

# Status

Planned

---

# Target Version

v0.4.0 Renderer

---

# Related Documents

- Event System
- ECS
- Core
