# Tic-Tac-Toe in C

Welcome to my simple Tic-Tac-Toe game! It's a fun little project where you play against the computer. The computer tries to be smart, but you can still beat it!

## Features
- Play vs computer.
- Computer blocks your winning moves (sometimes!).
- Nice board display, easy to follow.
- Game tells if you win, lose, or draw.

## How to Run
1. Clone the repo:
   ```bash
   git clone https://github.com/anousonephyakeo/tic_toc.git
   cd tic-tac-toe-c
   ```

2. Compile it:
   ```bash
   gcc tic_tac_toe.c -o tic_tac_toe
   ```

3. Run it:
   ```bash
   ./tic_tac_toe
   ```

## How to Play
- The board shows numbers (1-9). Pick a number to make your move.
- Type your move when it's your turn.
- The computer plays automatically after you.
- Game ends if someone wins or it's a draw.

## Functions Explained

### `initializeBoard()`
- Sets up the board with numbers 1-9.

### `displayBoard()`
- Shows the current board in a nice format.

### `checkWinner()`
- Checks if someone wins.

### `isDraw()`
- Checks if the board is full (draw).

### `playerMove()`
- Lets you pick a move. Checks if the move is valid.

### `findBestMove()`
- Finds the best move for computer or player to win.

### `computerMove()`
- Handles the computer's turn. Tries to win, block you, or picks randomly.

### `main()`
- Runs the game. Switches turns, checks for winner or draw, and prints results.

## Example Game
```
Welcome to Tic-Tac-Toe!
 1 | 2 | 3 
---|---|---
 4 | 5 | 6 
---|---|---
 7 | 8 | 9 

Your turn:
Enter your move (1-9): 5
 1 | 2 | 3 
---|---|---
 4 | X | 6 
---|---|---
 7 | 8 | 9 

Computer's turn:
Computer chose: 1
 O | 2 | 3 
---|---|---
 4 | X | 6 
---|---|---
 7 | 8 | 9 
...
```

## Future Ideas
- Make AI smarter (maybe unbeatable?).
- Add replay option.
- Use colors for better look.

## License
MIT License. Feel free to use or change it.

---

Hope you enjoy! Let me know if something's broken or if you got cool ideas. Have fun!
