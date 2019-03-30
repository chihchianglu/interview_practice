//
// Created by Lu, Chih-chiang on 2019-02-02.
//

/**
 * 01 Matrix
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 *
 * The distance between two adjacent cells is 1.
 * Example 1:
 * Input:
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Output:
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Example 2:
 *
 * Input:
 *
 * 0 0 0
 * 0 1 0
 * 1 1 1
 *
 * Output:
 *
 * 0 0 0
 * 0 1 0
 * 1 2 1
 *
 * Note:
 *
 * - The number of elements of the given matrix will not exceed 10,000.
 * - There are at least one 0 in the given matrix.
 * - The cells are adjacent in only four directions: up, down, left and right.
 */

#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
    std::vector<std::vector<int>> res(rows, std::vector<int>(cols, std::numeric_limits<int>::max() - 1));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (matrix[i][j] == 0) {
          res[i][j] = 0;
        } else {
          if (i > 0) {
            res[i][j] = std::min(res[i][j], res[i - 1][j] + 1);
          }
          if (j > 0) {
            res[i][j] = std::min(res[i][j], res[i][j - 1] + 1);
          }
        }
      }
    }
    for (int i = rows - 1; i >= 0; --i) {
      for (int j = cols - 1; j >= 0; --j) {
        if (res[i][j] != 0 && res[i][j] != 1) {
          if (i < rows - 1) {
            res[i][j] = std::min(res[i][j], res[i + 1][j] + 1);
          }
          if (j < cols - 1) {
            res[i][j] = std::min(res[i][j], res[i][j + 1] + 1);
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec =
      {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
       {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
       {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1},
       {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
  Solution::updateMatrix(vec);
  return 0;
}
