//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Search a 2D Matrix II
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * 1. Integers in each row are sorted in ascending from left to right.
 * 2. Integers in each column are sorted in ascending from top to bottom.
 * Example:
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 *
 * Given target = 5, return true.
 * Given target = 20, return false.
 *
 * Solution
 *
 * If we stand on the top-right corner of the matrix and look diagonally,
 * it's kind of like a BST, we can go through this matrix to find the target like how we traverse the BST.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
    if (rows == 0 || cols == 0) {
      return false;
    } else if (target < matrix[0][0] || target > matrix.back().back()) {
      return false;
    }

    int i = 0, j = cols - 1;
    while (i < rows && j >= 0) {
      if (target == matrix[i][j]) {
        return true;
      } else if (target < matrix[i][j]) {
        --j;
      } else {
        ++i;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>>
      vec = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  if (!Solution::searchMatrix(vec, 5)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::searchMatrix(vec, 20)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
