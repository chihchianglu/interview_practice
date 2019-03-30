//
// Created by Lu, Chih-chiang on 2019-03-11.
//

/**
 * Max Area of Island
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are
 * surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 *
 * Example 1:
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 *
 * Example 2:
 *
 * [[0,0,0,0,0,0,0,0]]
 *
 * Given the above grid, return 0.
 *
 * Note: The length of each dimension in the given grid does not exceed 50.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int rows = grid.size(), cols = rows ? grid[0].size() : 0, res = 0;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col] != 1) {
          continue;
        }
        int count = 0;
        std::queue<std::vector<int>> q{{{row, col}}};
        grid[row][col] = -1;
        while (!q.empty()) {
          auto cur = q.front();
          q.pop();
          for (auto &dir : dirs) {
            int neighbor_x = cur[0] + dir[0], neighbor_y = cur[1] + dir[1];
            if (neighbor_x < 0 || neighbor_x >= rows || neighbor_y < 0 || neighbor_y >= cols
                || grid[neighbor_x][neighbor_y] <= 0) {
              continue;
            }
            grid[neighbor_x][neighbor_y] = -1;
            q.push({neighbor_x, neighbor_y});
          }
          ++count;
        }
        res = std::max(res, count);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec_1 =
      {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
       {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
       {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  std::vector<std::vector<int>> vec_2 = {{0, 0, 0, 0, 0, 0, 0, 0}};

  if (Solution::maxAreaOfIsland(vec_1) != 6) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxAreaOfIsland(vec_2) != 0) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
