//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * A partially filled sudoku which is valid.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * Example 1:
 *
 * Input:
 * [
 *  ['5','3','.','.','7','.','.','.','.'],
 *  ['6','.','.','1','9','5','.','.','.'],
 *  ['.','9','8','.','.','.','.','6','.'],
 *  ['8','.','.','.','6','.','.','.','3'],
 *  ['4','.','.','8','.','3','.','.','1'],
 *  ['7','.','.','.','2','.','.','.','6'],
 *  ['.','6','.','.','.','.','2','8','.'],
 *  ['.','.','.','4','1','9','.','.','5'],
 *  ['.','.','.','.','8','.','.','7','9']
 * ]
 * Output: true
 *
 * Example 2:
 *
 * Input:
 * [
 *  ['8','3','.','.','7','.','.','.','.'],
 *  ['6','.','.','1','9','5','.','.','.'],
 *  ['.','9','8','.','.','.','.','6','.'],
 *  ['8','.','.','.','6','.','.','.','3'],
 *  ['4','.','.','8','.','3','.','.','1'],
 *  ['7','.','.','.','2','.','.','.','6'],
 *  ['.','6','.','.','.','.','2','8','.'],
 *  ['.','.','.','4','1','9','.','.','5'],
 *  ['.','.','.','.','8','.','.','7','9']
 * ]
 * Output: false
 *
 * Explanation: Same as Example 1, except with the 5 in the top left corner being
 * modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 *
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool isValidSudoku(std::vector<std::vector<char>> &board) {
    if (board.empty() || board[0].empty()) {
      return false;
    }
    int m = board.size(), n = board[0].size();
    // 1st sub = under this row/col/box
    // 2nd sub = this number in index
    // value = occur how many times
    std::vector<std::vector<bool>> row_flag(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> col_flag(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> box_flag(m, std::vector<bool>(n, false)); // from 0 ~ 8
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0' - 1;
          int k = (i / 3) * 3 + j / 3;
          if (row_flag[i][num] || col_flag[j][num] || box_flag[k][num]) {
            return false;
          }
          row_flag[i][num] = col_flag[j][num] = box_flag[k][num] = true;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> vec_1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  std::vector<std::vector<char>> vec_2 = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  if (!Solution::isValidSudoku(vec_1)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::isValidSudoku(vec_2)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
