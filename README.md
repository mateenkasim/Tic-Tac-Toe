# Tic-Tac-Toe
Tic Tac Toe between two players, written in C++.<br>
Currently run on the command line, display is text-based.<br>
Plays on an N x N grid, with N chosen by the players as long as it fits on the command line.

## Compile/Run
Compile on Mac using<br>
<code> c++ ttt.cpp ttt_func.cpp -o ttt </code> <br>
Run using<br>
<code>./ttt</code>

## Play
1. Game asks for number of rows in board, which will determine shape of board. Entering 3 will give a 3x3 board, 4 gives a 4x4 board, etc.
2. Game asks Player 1 for row and column.
3. Game asks Player 2 for row and column.
4. Steps 2 and 3 repeat until a player wins. Diagonal wins are only possible when row width is an odd number.
