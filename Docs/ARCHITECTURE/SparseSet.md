# Sparse Set

## Purpose

Sparse Set is a cache-friendly data structure used by the Aurora ECS.

It provides:

- O(1) insertion
- O(1) removal
- O(1) lookup

while keeping active entities stored contiguously in memory.

---

## Data Layout

Sparse Set consists of two arrays:

- Sparse Array
- Dense Array

---

## Dense Array

Stores active entity IDs.

Example:

```
[1][5][10]
```

---

## Sparse Array

Maps entity IDs to dense array indices.

Example:

```
1 -> 0
5 -> 1
10 -> 2
```

---

## Planned Features

- Component storage
- Views
- Iterators
- ECS queries
