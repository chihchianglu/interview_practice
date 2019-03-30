//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Magic Squares In Grid
 *
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that
 * each row, column, and both diagonals all have the same sum.
 *
 * Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
 *
 * Example 1:
 *
 * Input: [[4,3,8,4],
 *         [9,5,1,9],
 *         [2,7,6,2]]
 * Output: 1
 *
 * Explanation:
 * The following subgrid is a 3 x 3 magic square:
 * 438
 * 951
 * 276
 *
 * while this one is not:
 * 384
 * 519
 * 762
 *
 * In total, there is only one magic square inside the given grid.
 *
 * Note:
 *
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * 0 <= grid[i][j] <= 15
 */

#include <vector>

class Solution {
 public:
  static int numMagicSquaresInside(std::vector<std::vector<int>> &grid) {
    int res = 0, rows = grid.size(), cols = grid[0].size();

    for (int row = 1; row < rows - 1; ++row) {
      for (int col = 1; col < cols - 1; ++col) {
        if (grid[row][col] == 5) { // the center of magic square is 5
          if (grid[row - 1][col - 1] <= 9 && grid[row - 1][col - 1] >= 1
              && grid[row][col - 1] <= 9 && grid[row][col - 1] >= 1
              && grid[row + 1][col - 1] <= 9 && grid[row + 1][col - 1] >= 1
              && grid[row + 1][col] <= 9 && grid[row + 1][col] >= 1
              && grid[row + 1][col + 1] <= 9 && grid[row + 1][col + 1] >= 1
              && grid[row][col + 1] <= 9 && grid[row][col + 1] >= 1
              && grid[row - 1][col + 1] <= 9 && grid[row - 1][col + 1] >= 1
              && grid[row - 1][col] <= 9 && grid[row - 1][col] >= 1) {
            if (grid[row - 1][col - 1] + grid[row - 1][col] + grid[row - 1][col + 1] == 15
                && grid[row][col - 1] + grid[row][col] + grid[row][col + 1] == 15
                && grid[row + 1][col - 1] + grid[row + 1][col] + grid[row + 1][col + 1] == 15
                && grid[row - 1][col - 1] + grid[row][col - 1] + grid[row + 1][col - 1] == 15
                && grid[row - 1][col] + grid[row][col] + grid[row + 1][col] == 15
                && grid[row - 1][col + 1] + grid[row][col + 1] + grid[row + 1][col + 1] == 15
                && grid[row - 1][col - 1] + grid[row][col] + grid[row + 1][col + 1] == 15
                && grid[row - 1][col + 1] + grid[row][col] + grid[row + 1][col - 1] == 15) {
              if (grid[row][col] != grid[row][col - 1]) {
                ++res;
              }
            }
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec1 = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  if (Solution::numMagicSquaresInside(vec1) != 1) {
    throw std::runtime_error("error");
  }
  return 0;
}
