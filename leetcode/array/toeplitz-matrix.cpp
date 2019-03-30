//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Toeplitz Matrix
 *
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 *
 * Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 *
 * Example 1:
 *
 * Input:
 * matrix = [
 *   [1,2,3,4],
 *   [5,1,2,3],
 *   [9,5,1,2]
 * ]
 * Output: True
 *
 * Explanation:
 * In the above grid, the diagonals are:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 * In each diagonal all elements are the same, so the answer is True.
 *
 * Example 2:
 *
 * Input:
 * matrix = [
 *   [1,2],
 *   [2,2]
 * ]
 * Output: False
 *
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 *
 * Note:
 *
 * 1. matrix will be a 2D array of integers.
 * 2. matrix will have a number of rows and columns in range [1, 20].
 * 3. matrix[i][j] will be integers in range [0, 99].
 *
 * Follow up:
 *
 * 1. What if the matrix is stored on disk, and the memory is limited
 *    such that you can only load at most one row of the  * matrix into the memory at once?
 * 2. What if the matrix is so large that you can only load up a partial row into the memory at once?
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size(), cols = rows == 0 ? 0 : matrix[0].size();

    for (int row = 0; row < rows - 1; ++row) {
      for (int col = 0; col < cols - 1; ++col) {
        if (matrix[row][col] != matrix[row + 1][col + 1]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix1 = {{1, 2}, {2, 2}};
  std::vector<std::vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};

  if (Solution::isToeplitzMatrix(matrix1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::isToeplitzMatrix(matrix2)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
