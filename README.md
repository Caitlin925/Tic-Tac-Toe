# Tic-Tac-Toe
A two-player console-based Tic Tac Toe game built in C++

------------------------------------------------------------

## Features
- Two-player gameplay (Player X vs. Player O)
- Turn-based input system
- 3x3 board rendered into the console
- Win-condition detection (rows, columns, diagonals)
- Tie (draw) detection
- Input validation to prevent invalid or duplicate moves

------------------------------------------------------------

## Technologies
- Language: C++
### Core Concepts
- Functions
- Loops
- 2D arrays
- Conditional logic
- Input validation
- Game state management

-------------------------------------------------------------
## Usage
- Open the file `TicTacToe.cpp` in your C++ IDE (e.g., VS Code, Code::Blocks, Visual Studio Code) and run the program.

### Example Output:
```cpp
Welcome to Tic-Tac-Toe!!
The first player to get 3 in a row wins!

Player 1 enter your name: player 1
Player 2 enter your name: player 2

player 1 is X's
player 2 is O's

- - - 
- - - 
- - - 

player 1's turn.
Pick a row (1, 2, or 3): 1
Pick a column (1, 2, or 3): 1

X - - 
- - - 
- - - 

player 2's turn.
Pick a row (1, 2, or 3): 2
Pick a column (1, 2, or 3): 2

X - - 
- O - 
- - - 

player 1's turn.
Pick a row (1, 2, or 3): 2
Pick a column (1, 2, or 3): 1

X - - 
X O - 
- - - 

player 2's turn.
Pick a row (1, 2, or 3): 3
Pick a column (1, 2, or 3): 2

X - - 
X O - 
- O - 

player 1's turn.
Pick a row (1, 2, or 3): 3
Pick a column (1, 2, or 3): 1

X - - 
X O - 
X O - 

player 1 wins!!

