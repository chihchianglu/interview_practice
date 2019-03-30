//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * N-Queens II
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
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
  static void solveNQueensDFS(std::vector<int> &pos, int row, int &res) {
    int n = pos.size();
    if (row == n) {
      ++res;
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
  static int totalNQueens(int n) {
    int res = 0;
    std::vector<int> pos(n, -1); // position for queens on each row
    solveNQueensDFS(pos, 0, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::totalNQueens(4) != 2) {
    throw std::runtime_error("error");
  }
  return 0;
}
