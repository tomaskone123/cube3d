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
