//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Island Perimeter
 *
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally).
 * The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
 * The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
 * One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 *
 * Example:
 *
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 *
 * Answer: 16 Explanation: The perimeter is the 16 yellow stripes in the image below:
 */

#include <vector>
#include <stdexcept>

// 这道题给了我们一个格子图，若干连在一起的格子形成了一个小岛，规定了图中只有一个相连的岛，且岛中没有湖，让我们求岛的周长。
// 我们知道一个格子有四条边，但是当两个格子相邻，周围为6，若某个格子四周都有格子，那么这个格子一条边都不算在周长里。
// 那么我们怎么统计出岛的周长呢？第一种方法，我们对于每个格子的四条边分别来处理，首先看左边的边，
// 只有当左边的边处于第一个位置或者当前格子的左面没有岛格子的时候，左边的边计入周长。其他三条边的分析情况都跟左边的边相似，这里就不多叙述了
class Solution {
 public:
  static int islandPerimeter(std::vector<std::vector<int>> &grid) {
    int rows = grid.size(), cols = rows ? grid[0].size() : 0, res = 0;
    if (rows == 0 || cols == 0) {
      return 0;
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        if (j == 0 || grid[i][j - 1] == 0) {
          ++res;
        }
        if (i == 0 || grid[i - 1][j] == 0) {
          ++res;
        }
        if (j == cols - 1 || grid[i][j + 1] == 0) {
          ++res;
        }
        if (i == rows - 1 || grid[i + 1][j] == 0) {
          ++res;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  if (Solution::islandPerimeter(vec) != 16) {
    throw std::runtime_error("error");
  }
  return 0;
}
