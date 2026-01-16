# Cube3D

**Cube3D** is a 3D graphical project developed in C, inspired by the classic raycasting technique. The project is designed to render 3D environments in real-time using a minimalistic approach, allowing users to navigate through a pseudo-3D world.

## Features

* Real-time 3D rendering using raycasting
* Player movement (forward, backward, strafe left/right)
* Collision detection with walls
* Basic textures for walls
* Simple minimap for orientation
* Configurable map files

## Requirements

* Unix-based OS (Linux, macOS)
* [MLX42](https://github.com/codam-coding-college/MLX42) or equivalent graphics library installed
* C compiler (gcc recommended)
* Make

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/tomaskone123/cube3d.git
   cd cube3d
   ```

2. Compile the project using Make:

   ```bash
   make
   ```

3. Run the executable with a map file:

   ```bash
   ./cube3d maps/map1.cub
   ```

## Controls

* **W** – Move forward
* **S** – Move backward
* **A** – Strafe left
* **D** – Strafe right
* **Arrow Keys** – Rotate view
* **ESC** – Exit

## Project Structure

```
cube3d/
├── src/          # Source files
├── include/      # Header files
├── maps/         # Map files
├── textures/     # Wall textures
├── Makefile
└── README.md
```

## Map File Format

* Maps are `.cub` files
* Each character represents a tile:

  * `1` – Wall
  * `0` – Empty space
  * `N/S/E/W` – Player starting position and orientation

## Contributing

Feel free to fork the repository, add features, or fix bugs. Pull requests are welcome!

## License

This project is licensed under the MIT License.












````markdown
*This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].*

# cub3D

## Description

**cub3D** is a 3D graphical project inspired by the classic game *Wolfenstein 3D*.
The goal of the project is to create a simple first-person 3D engine using **raycasting**, written entirely in **C**, and rendered using the **MiniLibX** graphical library.

The program parses a `.cub` configuration file that defines textures, colors, and a 2D map layout, then renders the map as a 3D environment where the player can move and rotate in real time. This project focuses on low-level graphics programming, mathematical concepts behind raycasting, memory management, and event handling.

## Instructions

### Requirements
- macOS or Linux
- `gcc` or `clang`
- `make`
- MiniLibX (provided by 42)

### Compilation
To compile the project, run:
```bash
make
````

This will generate the executable:

```bash
./cub3D
```

### Execution

Run the program with a valid `.cub` map file:

```bash
./cub3D maps/example.cub
```

### Controls

* `W` / `A` / `S` / `D` – Move the player
* `←` / `→` – Rotate camera
* `ESC` – Exit the program
* Window close button – Exit the program

## Map Format (.cub)

The `.cub` file contains:

* Paths to wall textures (`NO`, `SO`, `WE`, `EA`)
* Floor and ceiling colors (RGB)
* A map composed of:

  * `1` for walls
  * `0` for empty space
  * `N`, `S`, `E`, `W` for player start position and orientation

Example:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
111111
100001
1000N1
111111
```

## Resources

* MiniLibX documentation: [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* Raycasting tutorial: [Lodev’s Raycasting Tutorial](http://lodev.org/cgtutor/raycasting.html)
* Additional references: Game programming tutorials, C graphics articles, 3D math resources

## AI Usage

AI was used as an assistant for non-core tasks, including:

* Debugging helper scripts for map validation
* Generating example `.cub` files
* Checking memory allocation and leaks
* Suggesting optimizations for helper functions

AI was **not** used to generate the main raycasting algorithm or core project logic.

```
```
