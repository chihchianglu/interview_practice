//
// Created by Lu, Chih-chiang on 2019-03-08.
//

/**
 * The Maze
 *
 * There is a ball in a maze with empty spaces and walls.
 * The ball can go through empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall. When the ball stops,
 * it could choose the next direction.
 *
 * Given the ball's start position, the destination and the maze,
 * determine whether the ball could stop at the destination.
 *
 * The maze is represented by a binary 2D array.
 * 1 means the wall and 0 means the empty space.
 * You may assume that the borders of the maze are all walls.
 * The start and destination coordinates are represented by row and column indexes.
 *
 * Example 1
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (4, 4)
 *
 * Output: true
 * Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
 *
 * Example 2
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (3, 2)
 *
 * Output: false
 * Explanation: There is no way for the ball to stop at the destination.
 *
 * Note:
 * - There is only one ball and one destination in the maze.
 * - Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
 * - The given maze does not contain border (like the red rectangle in the example pictures),
 *   but you could assume the border of the maze are all walls.
 * - The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &destination) {
    int rows = maze.size(), cols = rows ? maze[0].size() : 0;
    if (rows == 0 || cols == 0) {
      return true;
    }
    std::queue<std::vector<int>> q;
    std::vector<std::vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    q.push(start);
    maze[start[0]][start[1]] = 2; // visited
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (cur == destination) {
        return true;
      }
      for (auto &dir : dirs) {
        int x = cur[0], y = cur[1];
        // Keep rolling in the current direction
        while (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != 1) {
          x += dir[0];
          y += dir[1];
        }
        // One step back
        x -= dir[0];
        y -= dir[1];
        // Check if it's visited
        if (maze[x][y] != 0) {
          continue;
        }
        // Mark as visited
        maze[x][y] = 2;
        // Continue rolling(or search) from [x, y]
        q.push({x, y});
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>>
      in_1_m = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
  std::vector<int> in_1_s = {0, 4};
  std::vector<int> in_1_d = {4, 4};
  std::vector<std::vector<int>>
      in_2_m = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
  std::vector<int> in_2_s = {0, 4};
  std::vector<int> in_2_d = {3, 2};
  if (!Solution::hasPath(in_1_m, in_1_s, in_1_d)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::hasPath(in_2_m, in_2_s, in_2_d)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
