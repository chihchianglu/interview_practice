//
// Created by Lu, Chih-chiang on 2019-01-05.
//

/**
 * Spiral Matrix
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    int rows = matrix.size(), cols = matrix[0].size(), up = 0, down = rows - 1, left = 0, right = cols - 1;
    std::vector<int> res;

    while (true) {
      // left -> right
      for (int i = left; i <= right; ++i) {
        res.push_back(matrix[up][i]);
      }
      if (++up > down) {
        break;
      }
      // up -> down
      for (int i = up; i <= down; ++i) {
        res.push_back(matrix[i][right]);
      }
      if (--right < left) {
        break;
      }
      // right -> left
      for (int i = right; i >= left; --i) {
        res.push_back(matrix[down][i]);
      }
      if (--down < up) {
        break;
      }
      // down -> up
      for (int i = down; i >= up; --i) {
        res.push_back(matrix[i][left]);
      }
      if (++left > right) {
        break;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> out1 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  std::vector<int> out2 = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

  if (Solution::spiralOrder(matrix1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::spiralOrder(matrix2) != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
