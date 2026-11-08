# So_long

A small 2D map-based game written in C using the MinilibX graphics library. The goal is to collect every collectible item and reach the exit without getting stuck behind walls.

This project follows the classic 42 School `so_long` project theme: validate a map, render the game world, accept keyboard input, and enforce win conditions.

## Features

- Validates map structure and game rules
- Ensures the map is playable via flood-fill path checking
- Renders a tile map with custom XPM sprite assets
- Handles player movement using keyboard controls
- Includes sample `.ber` maps for testing

## Project structure

- `main.c` — program entry point and startup logic
- `check_map.c` — map validation checks
- `check_valid_path.c` — valid path/flood-fill logic
- `moves.c` — movement and input handling
- `rendering.c` — map rendering and graphical display
- `images/` — sprite assets used in the game
- `maps/` — sample levels in `.ber` format
- `Makefile` — build configuration

## Requirements

- macOS environment with MinilibX available
- `make`
- `cc` / clang

## Build

```bash
git clone https://github.com/safouankh/so_long.git
cd so_long
make
```

This will create the executable:

```bash
./so_long
```

## Run

```bash
./so_long maps/test.ber
```

You can also try one of the included maps:

```bash
./so_long maps/1337.ber
./so_long maps/map2.ber
```

## Controls

- `W` / `A` / `S` / `D` — move up, left, down, right
- Arrow keys also work
- `ESC` — quit the game

## Map format

The game reads a map file with the `.ber` extension. Supported characters are:

- `0` — empty tile
- `1` — wall
- `C` — collectible
- `E` — exit
- `P` — player starting position

A valid map must:

- be rectangular
- be surrounded by walls
- contain exactly one player start (`P`)
- contain at least one collectible (`C`)
- contain exactly one exit (`E`)
- be solvable from the start to the exit

Example:

```text
111111
10001
101C1
1P0E1
111111
```

## Notes

This project is a C implementation of a classic game loop and tile map renderer, designed for a 42-style coding challenge. It includes custom helper functions for printing, map reading, and resource cleanup.

## License

This project is provided as-is for educational purposes.
