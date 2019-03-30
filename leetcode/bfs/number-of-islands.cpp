//
// Created by Lu, Chih-chiang on 2019-03-08.
//

/**
 * Number of Islands
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int numIslands(std::vector<std::vector<char>> &grid) {
    int rows = grid.size(), cols = rows ? grid[0].size() : 0, res = 0;
    if (rows == 0 || cols == 0) {
      return res;
    }
    std::queue<std::vector<int>> q;
    std::vector<int> dir_x = {-1, 0, 0, 1};
    std::vector<int> dir_y = {0, -1, 1, 0};

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == '1') {
          q.push({i, j});
          while (!q.empty()) {
            auto x = q.front()[0];
            auto y = q.front()[1];
            grid[x][y] = '0';
            q.pop();
            for (int k = 0; k < 4; ++k) {
              auto neighbor_x = x + dir_x[k];
              auto neighbor_y = y + dir_y[k];
              if (neighbor_x >= 0 && neighbor_x < rows && neighbor_y >= 0 && neighbor_y < cols
                  && grid[neighbor_x][neighbor_y] == '1') {
                q.push({neighbor_x, neighbor_y});
                grid[neighbor_x][neighbor_y] = '0';
              }
            }
          }
          ++res;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> in_1 =
      {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
  std::vector<std::vector<char>> in_2 =
      {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
  if (Solution::numIslands(in_1) != 1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::numIslands(in_2) != 3) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
