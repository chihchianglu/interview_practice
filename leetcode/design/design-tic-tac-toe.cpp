//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Design Tic-Tac-Toe
 *
 * Design a Tic-tac-toe game that is played between two players on a n x n grid.
 *
 * You may assume the following rules:
 *
 * A move is guaranteed to be valid and is placed on an empty block.
 * Once a winning condition is reached, no more moves is allowed.
 * A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
 *
 * Example:
 *
 * Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
 *
 * TicTacToe toe = new TicTacToe(3);
 *
 * toe.move(0, 0, 1); -> Returns 0 (no one wins)
 * |X| | |
 * | | | |    // Player 1 makes a move at (0, 0).
 * | | | |
 *
 * toe.move(0, 2, 2); -> Returns 0 (no one wins)
 * |X| |O|
 * | | | |    // Player 2 makes a move at (0, 2).
 * | | | |
 *
 * toe.move(2, 2, 1); -> Returns 0 (no one wins)
 * |X| |O|
 * | | | |    // Player 1 makes a move at (2, 2).
 * | | |X|
 *
 * toe.move(1, 1, 2); -> Returns 0 (no one wins)
 * |X| |O|
 * | |O| |    // Player 2 makes a move at (1, 1).
 * | | |X|
 *
 * toe.move(2, 0, 1); -> Returns 0 (no one wins)
 * |X| |O|
 * | |O| |    // Player 1 makes a move at (2, 0).
 * |X| |X|
 *
 * toe.move(1, 0, 2); -> Returns 0 (no one wins)
 * |X| |O|
 * |O|O| |    // Player 2 makes a move at (1, 0).
 * |X| |X|
 *
 * toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
 * |X| |O|
 * |O|O| |    // Player 1 makes a move at (2, 1).
 * |X|X|X|
 *
 * Follow up:
 * Could you do better than O(n^2) per move() operation?
 *
 * Hint:
 * Could you trade extra space such that move() operation can be done in O(1)?
 * You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
 *
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe *obj = new TicTacToe(n)
 * int param_1 = obj->move(row,col,player)
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class TicTacToe_v1 {
 public:
  /** Initialize your data structure here. */
  TicTacToe_v1(int n) : board_(n, std::vector<int>(n, 0)) {}

  int move(int row, int col, int player) {
    board_[row][col] = player;
    int i = 0, j = 0, n = board_.size();

    // check row
    for (j = 1; j < n; ++j) {
      if (board_[row][j] != board_[row][j - 1]) {
        break;
      }
    }
    if (j == n) {
      return player;
    }

    // check col
    for (i = 1; i < n; ++i) {
      if (board_[i][col] != board_[i - 1][col]) {
        break;
      }
    }
    if (i == n) {
      return player;
    }

    // check diagonal
    if (row == col) {
      for (i = 1; i < n; ++i) {
        if (board_[i][i] != board_[i - 1][i - 1]) {
          break;
        }
      }
      if (i == n) {
        return player;
      }
    }
    if (row + col == n - 1) {
      for (i = 1; i < n; ++i) {
        if (board_[i][n - 1 - i] != board_[i - 1][n - i]) {
          break;
        }
      }
      if (i == n) {
        return player;
      }
    }
    return 0;
  }

 private:
  std::vector<std::vector<int>> board_;
};

class TicTacToe {
 public:
  TicTacToe(int n) : rows_(n, 0), cols_(n, 0), N(n), diag_(0), rev_diag_(0) {}

  int move(int row, int col, int player) {
    int add = player == 1 ? 1 : -1;
    rows_[row] += add;
    cols_[col] += add;
    diag_ += (row == col ? add : 0);
    rev_diag_ += (row + col == N - 1 ? add : 0);
    return (std::abs(rows_[row]) == N || std::abs(cols_[col]) == N || std::abs(diag_) == N || std::abs(rev_diag_) == N)
           ? player : 0;
  }
 private:
  std::vector<int> rows_, cols_;
  int diag_, rev_diag_, N;
};

int main(int argc, char *argv[]) {
  TicTacToe_v1 t1(3);
  TicTacToe t2(3);
  return 0;
}
