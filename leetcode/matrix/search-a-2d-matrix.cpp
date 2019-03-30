//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Search a 2D Matrix
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * Example:
 *
 * Consider the following matrix:
 *
 * [
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 *
 * Given target = 3, return true.
 *
 *
 * [
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 * Given target = 13, return false
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
    int left = 0, right = rows * cols - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      // mapping from 1-dimension to 2-dimension matrix[idx / cols][idx % cols]
      if (matrix[mid / cols][mid % cols] == target) {
        return true;
      } else if (target < matrix[mid / cols][mid % cols]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  if (!Solution::searchMatrix(vec, 3)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::searchMatrix(vec, 13)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
