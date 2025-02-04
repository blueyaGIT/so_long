<p align="center">
  <img src="https://github.com/blueyaGIT/blueyaGIT/blob/master/42_badges/so_longe.png?raw=true" alt="so_long"/>
</p>

<p align="center">
  Score: <i>100/100</i><br>
  Finished: <i>24.01.2025</i><br>
</p>

###

`so_long` is a 2D game project using the `MiniLibX` graphics library. The objective is to create a simple top-down game where the player navigates through a map, collecting items and reaching an exit while avoiding obstacles. This project is part of the 42 School curriculum.

## Usage

To use `so_long`, clone the repository in the root of your project using one of the following commands:

#### SSH
```bash
git clone git@github.com:blueyaGIT/so_long.git
```
#### HTTPS
```bash
git clone https://github.com/blueyaGIT/so_long.git
```
#### GitHub CLI
```bash
gh repo clone blueyaGIT/so_long
```
This will create a directory called `so_long/`. Enter it with the command:

```bash
cd so_long
```

### Compiling

To compile the game, run:

```bash
make
```

This will generate the `so_long` executable.

### Running the Game

Execute the game with a map file:

```bash
./so_long "path/to/map"
```

## Map Format

The game map is a `.ber` file that follows these rules:
- Must be rectangular.
- Must have at least one exit (`E`).
- Must have at least one collectible (`C`).
- Must have exactly one player starting position (`P`).
- Walls (`1`) must enclose the map.
- Walkable paths are represented by (`0`).

Example:
```
111111
1P0C01
100001
1C0E11
111111
```

## Controls

- `↑` - Move up
- `←` - Move left
- `↓` - Move down
- `→` - Move right
- `ESC` - Quit game

## Files

- `main.c` - Main game logic.
- `map_*.c` - Handles map parsing and validation.
- `map_render.c` - Handles rendering with <a href="https://github.com/codam-coding-college/MLX42.git" target="_blank">MLX42</a>.
- `getch.c` - Handles player movement and input.
- `so_long.h` - Header file containing function prototypes and necessary includes.
- `Makefile` - Automates compilation of the project.

## Notes

- `MLX42` is `NOT` required to run the project due to it being added as submodule by the Makefile.
- The game window closes when the player reaches the exit after collecting all items.

For more details, refer to the project documentation or the `42` subject PDF.

## 🚀 Next Project

<a href="https://github.com/blueyaGIT/push_swap"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=push_swap"></a>

## ⏳ Previous Project

<a href="https://github.com/blueyaGIT/minitalk"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=minitalk"></a>
