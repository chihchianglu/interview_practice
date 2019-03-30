//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Valid Tic-Tac-Toe State
 *
 * A Tic-Tac-Toe board is given as a string array board.
 * Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
 *
 * The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.
 *
 * Here are the rules of Tic-Tac-Toe:
 *
 * Players take turns placing characters into empty squares (" ").
 * The first player always places "X" characters, while the second player always places "O" characters.
 * "X" and "O" characters are always placed into empty squares, never filled ones.
 * The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
 * The game also ends if all squares are non-empty.
 * No more moves can be played if the game is over.
 *
 * Example 1:
 *
 * Input: board = ["O  ", "   ", "   "]
 * Output: false
 *
 * Explanation: The first player always plays "X".
 *
 * Example 2:
 *
 * Input: board = ["XOX", " X ", "   "]
 * Output: false
 *
 * Explanation: Players take turns making moves.
 *
 * Example 3:
 *
 * Input: board = ["XXX", "   ", "OOO"]
 * Output: false
 *
 * Example 4:
 *
 * Input: board = ["XOX", "O O", "XOX"]
 * Output: true
 *
 * Note:
 *
 * - board is a length-3 array of strings, where each string board[i] has length 3.
 * - Each board[i][j] is a character in the set {" ", "X", "O"}.
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool validTicTacToe(std::vector<std::string> &board) {
    bool xwin = false, owin = false;
    std::vector<int> rows(3), cols(3);
    int diag = 0, antidiag = 0, turns = 0;

    for (int row = 0; row < 3; ++row) {
      for (int col = 0; col < 3; ++col) {
        if (board[row][col] == 'X') {
          ++rows[row];
          ++cols[col];
          ++turns;
          if (row == col) {
            ++diag;
          }
          if (row + col == 2) {
            ++antidiag;
          }
        } else if (board[row][col] == 'O') {
          --rows[row];
          --cols[col];
          --turns;
          if (row == col) {
            --diag;
          }
          if (row + col == 2) {
            --antidiag;
          }
        }
      }
    }

    xwin = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || diag == 3
        || antidiag == 3;
    owin =
        rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || cols[0] == -3 || cols[1] == -3 || cols[2] == -3 || diag == -3
            || antidiag == -3;

    if (turns != 0 && turns != 1) {
      return false;
    }
    if ((xwin && turns == 0) || (owin && turns == 1)) {
      return false;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
