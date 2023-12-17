# Connect 4

This is a C++ program that implements the classic game of Connect 4. You can play against a computer that is running an implementation of the minimax algorithm with alpha beta pruning.

This is also the second of three more projects. the first is a Tic Tac Toe game that didn't include alpha-beta pruning and was done in Python.

## How to run

To start the game, open a terminal and navigate to the folder where you saved the file `main.cp`. Then compile with the following command:

`g++ -Wall -Wextra -Werror main.cpp board.cpp ai.cpp -o main.exe`

Followed by:

`./main.exe `

## How to play

The game board is a 6x7 grid of squares. The first player uses X and the second player uses O. The players take turns to place their symbol at the bottom of a collumn, trying to form a horizontal, vertical, or diagonal line of four symbols. The player who does so first wins the game. If all squares are filled and no one wins, the game is a draw.

To make a move, simply choose the collumn you want to play on. The game will check if the move is valid and update the board accordingly. 

