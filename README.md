# So Long

The So Long project at 42 is a beginner-level game development project that helps students learn the basics of graphics programming and game mechanics using the MiniLibX library. Here's an overview of the project:

![ezgif-7-74811bc2bb](https://github.com/LyudmilaKostanyan/so_long/assets/119743330/dd1f85e7-c56e-47a7-8e17-7a215f7e9559)

## Usage

Compile the code using the provided Makefile. Run the executable, providing the path to a valid map file.

Example usage:

```
./so_long maps/map_1.ber
```

## Objectives
- **Create a 2D game**: Develop a simple 2D game where a player can navigate through a map, collect items, and reach an exit to win.
- **Learn graphics programming**: Gain experience using the MiniLibX library for rendering graphics and handling user input in C.

## Key Components
1. **Map File**:
   - The game map is defined in a `.ber` file, which is a plain text file containing characters that represent different elements of the game.
   - Characters used in the map:
     - `1`: Wall (impassable terrain)
     - `0`: Empty space (passable terrain)
     - `P`: Player's starting position
     - `C`: Collectibles
     - `E`: Exit

2. **Game Elements**:
   - **Player**: Moves through the map, controlled by keyboard input.
   - **Collectibles**: Items that the player must collect.
   - **Exit**: The player must reach this after collecting all collectibles to win the game.

3. **Graphics and Input Handling**:
   - Use MiniLibX to render the map and game elements.
   - Handle keyboard input to move the player character.

## Requirements
- **Display the Map**: Render the game map on the screen.
- **Player Movement**: Allow the player to move up, down, left, and right.
- **Collecting Items**: Update the map and game state when the player collects items.
- **Winning Condition**: Check if the player has collected all items and reached the exit.

## Learning Outcomes
- **Graphics Programming**: Understand the basics of rendering graphics and handling user input using MiniLibX.
- **Game Loop**: Implement a simple game loop that updates the game state and renders the game continuously.
- **File Parsing**: Read and interpret a map file to generate the game world.
