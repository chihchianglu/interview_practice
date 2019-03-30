//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Sudoku Solver
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool isValid(std::vector<std::vector<char>> &board, int i, int j) {
    // check col
    for (int col = 0; col < 9; ++col) {
      if (col != j && board[i][j] == board[i][col]) {
        return false;
      }
    }
    // check row
    for (int row = 0; row < 9; ++row) {
      if (row != i && board[i][j] == board[row][j]) {
        return false;
      }
    }
    // check box
    for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; ++row) {
      for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; ++col) {
        if ((row != i || col != j) && board[i][j] == board[row][col]) {
          return false;
        }
      }
    }
    return true;
  }
  static bool solveSudokuDFS(std::vector<std::vector<char>> &board, int i, int j) {
    if (i == 9) {
      return true;
    } else if (j >= 9) {
      return solveSudokuDFS(board, i + 1, 0);
    }
    if (board[i][j] == '.') {
      for (int k = 1; k <= 9; ++k) {
        board[i][j] = char(k + '0');
        if (isValid(board, i, j)) {
          if (solveSudokuDFS(board, i, j + 1)) {
            return true;
          }
        }
        board[i][j] = '.';
      }
    } else {
      return solveSudokuDFS(board, i, j + 1);
    }
    return false;
  }
  static void solveSudoku(std::vector<std::vector<char>> &board) {
    if (board.empty() || board.size() != 9 || board[0].size() != 9) {
      return;
    }
    solveSudokuDFS(board, 0, 0);
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> vec =
      {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
       {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
       {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
       {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
       {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  std::vector<std::vector<char>> out =
      {{'5', '3', '4', '6', '7', '8', '9', '1', '2'}, {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
       {'1', '9', '8', '3', '4', '2', '5', '6', '7'}, {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
       {'4', '2', '6', '8', '5', '3', '7', '9', '1'}, {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
       {'9', '6', '1', '5', '3', '7', '2', '8', '4'}, {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
       {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

  Solution::solveSudoku(vec);
  if (vec != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
