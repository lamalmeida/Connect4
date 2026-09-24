# Connect Four

A C++ Connect Four game with a computer opponent implemented using minimax search and alpha-beta pruning.

This project followed the earlier Python Tic-Tac-Toe minimax project and explores the same game-search ideas on a larger state space.

## Build

From the repository root:

```bash
g++ -Wall -Wextra main.cpp board.cpp ai.cpp -o connect4
```

Then run:

```bash
./connect4
```

On Windows, compile to `connect4.exe` and run that executable instead.

## How to play

Choose whether to move first or second, then enter a column number from 0 to 6. Pieces fall to the lowest available position in that column.

The first player to connect four pieces horizontally, vertically, or diagonally wins.

## Implementation

The project demonstrates:
- compact board-state representation,
- legal move generation and undo,
- terminal-state evaluation,
- minimax search, and
- alpha-beta pruning to reduce the number of explored positions.
