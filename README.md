# TIC-TAC-TOE (C++)

## Overview

This is a console-based implementation of the classic Tic-Tac-Toe game written in C++. The game allows two players to compete against each other, with one player using the "O" symbol and the other using the "X" symbol. The objective of the game is to align three of your symbols (either "O" or "X") in a row, column, or diagonal to win the game.

## Features

- **Interactive Gameplay:** Players can navigate the board using arrow keys and mark their positions with the spacebar.
- **Turn-Based Play:** The game alternates between two players, displaying whose turn it is.
- **Winning Logic:** The game checks for win conditions after each move and declares the winner.
- **Draw Condition:** If the board is filled without any player winning, the game declares a tie.
- **Clear Interface:** The game resets and clears the console after each round, ensuring a smooth playing experience.

## Controls

- **Arrow Keys:** Move the cursor around the board.
  - **Up Arrow:** Move the cursor up.
  - **Down Arrow:** Move the cursor down.
  - **Left Arrow:** Move the cursor left.
  - **Right Arrow:** Move the cursor right.
- **Spacebar:** Place the current player's symbol at the cursor position.

## Game Flow

1. The game starts with an empty 3x3 board.
2. Player O begins the game, followed by Player X.
3. Players take turns to move the cursor and place their symbol on the board.
4. The game checks for a win condition after each move:
   - If a player has aligned three symbols in a row, column, or diagonal, they win.
   - If the board is full and no player has won, the game ends in a draw.
5. After a win or draw, the game board resets, and the next round begins with the current player's turn.

## How to Run

1. Compile the code using a C++ compiler.
2. Run the executable in a console/terminal.
3. Follow the instructions displayed on the screen to play the game.

## Future Enhancements

- Implementing an AI opponent for single-player mode.
- Adding a graphical interface for improved user experience.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Enjoy playing Tic-Tac-Toe!
