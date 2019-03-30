//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * N-Queens
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement,
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool isValid(std::vector<int> &pos, int row, int col) {
    for (int i = 0; i < row; ++i) {
      // check:
      // 1. col not the same
      // 2. diagnal not the same -> row1 - row2 != col1 - col2
      if (col == pos[i] || std::abs(row - i) == std::abs(col - pos[i])) {
        return false;
      }
    }
    return true;
  }
  static void solveNQueensDFS(std::vector<int> &pos, int row, std::vector<std::vector<std::string>> &res) {
    int n = pos.size();
    if (row == n) {
      // collect result
      std::vector<std::string> out(n, std::string(n, '.'));
      for (int i = 0; i < n; ++i) {
        out[i][pos[i]] = 'Q';
      }
      res.push_back(out);
    } else {
      for (int col = 0; col < n; ++col) {
        if (isValid(pos, row, col)) {
          pos[row] = col;
          solveNQueensDFS(pos, row + 1, res);
          pos[row] = -1;
        }
      }
    }
  }
  static std::vector<std::vector<std::string> > solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<int> pos(n, -1); // position for queens on each row
    solveNQueensDFS(pos, 0, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<std::string>> out = {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
  if (Solution::solveNQueens(4) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
