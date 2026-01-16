# 🎮 cub3D
> A 3D raycasting engine written in C

*Created as part of the 42 curriculum by **tkonecny** and **skuik***

---

## Description

**cub3D** is a 3D graphical project written in **C**, inspired by early first-person games such as *Wolfenstein 3D*. The main goal is to build a simple real-time 3D rendering engine using the **raycasting** technique and the **MLX42** graphical library.

The program reads a `.cub` configuration file describing textures, colors, and a 2D map layout, then renders it as a navigable pseudo-3D environment. The player can move, rotate, and explore the map while collision detection prevents walking through walls.

### Learning Objectives

- Understanding the mathematics behind raycasting
- Low-level graphics programming
- Event handling and real-time rendering
- Parsing and validating configuration files
- Memory management in C

## Features

| Feature | Description |
|---------|-------------|
| **3D Raycasting** | Real-time 3D rendering engine |
| **Player Movement** | Forward, backward, strafe left/right |
| **Camera Rotation** | Smooth 360° camera control |
| **Collision Detection** | Walk through walls prevention |
| **Textured Walls** | Custom texture mapping |
| **Minimap** | Real-time map display |
| **Configurable Maps** | Custom `.cub` map files |

---

## Getting Started

# Compile
make

# Run
./cub3D maps/small.cub (or any map you want)
```

###  Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` / `→` | Rotate view |
| `ESC` | Exit |

---

## Map File Format (`.cub`)

The `.cub` file defines textures, colors, and the map layout with a simple configuration format.

### Map Characters

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty space |
| `N`, `S`, `E`, `W` | Player spawn & direction |


### Example `.cub` File
```
SO ./textures/brick_wall.png
NO ./textures/brick_wall.png
WE ./textures/brick_wall.png
EA ./textures/brick_wall.png
C         255,150,40
F         0,0,0


111111111
100000001
1000N0001
100000001
111111111

```

---

## Resources

- [cub3D Documentation (42)](https://harm-smits.github.io/42docs/projects/cub3d)
- [MLX Examples](https://github.com/terry-yes/mlx_example)
- [Raycasting Explanation](https://hackmd.io/@nszl/H1LXByIE2)
- [Raycasting Video Tutorial](https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCXqoZAc8-tyDSaO8jnabOEFhdTQfx77)

---

## AI Usage Notice

Artificial Intelligence tools were used **as assistance only**, not to generate core project logic.

### How AI Was Used:
- Verifying **math calculations** for raycasting
- Clarifying trigonometry and vector math concepts
- Generating example `.cub` map files for testing
- Suggesting testing strategies and edge cases
- High-level explanations of raycasting concepts
- README structuring and presentation

