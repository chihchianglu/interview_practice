//
// Created by Lu, Chih-chiang on 2019-03-08.
//

/**
 * The Maze II
 *
 * There is a ball in a maze with empty spaces and walls.
 * The ball can go through empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
 *
 * Given the ball's start position, the destination and the maze,
 * find the shortest distance for the ball to stop at the destination.
 * The distance is defined by the number of empty spaces traveled by the ball
 * from the start position (excluded) to the destination (included). If the ball
 * cannot stop at the destination, return -1.
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
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
 * Output: 12
 * Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
 *              The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
 * Output: -1
 * Explanation: There is no way for the ball to stop at the destination.
 *
 * Note:
 *
 * 1. There is only one ball and one destination in the maze.
 * 2. Both the ball and the destination exist on an empty space,
 *    and they will not be at the same position initially.
 * 3. The given maze does not contain border (like the red rectangle in the example pictures),
 *    but you could assume the border of the maze are all walls.
 * 4. The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
 */

#include <queue>
#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int shortestDistance(std::vector<std::vector<int>> &maze,
                              std::vector<int> &start,
                              std::vector<int> &destination) {
    int rows = maze.size(), cols = rows ? maze[0].size() : 0;
    if (rows == 0 || cols == 0) {
      return true;
    }
    std::queue<std::vector<int>> q;
    std::vector<std::vector<int>> distance(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
    std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    q.push(start);
    distance[start[0]][start[1]] = 0;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto &dir : dirs) {
        int x = cur[0] + dir[0], y = cur[1] + dir[1]; // move first so the count would be accurate
        int count = 0;
        // Keep rolling in the current direction
        while (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0) {
          ++count;
          x += dir[0];
          y += dir[1];
        }
        // One step back
        x -= dir[0];
        y -= dir[1];
        if (distance[x][y] > distance[cur[0]][cur[1]] + count) {
          distance[x][y] = distance[cur[0]][cur[1]] + count;
          // Continue rolling(or search) from [x, y]
          q.push({x, y});
        }
      }
    }
    int res = distance[destination[0]][destination[1]];
    return res == std::numeric_limits<int>::max() ? -1 : res;
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
  if (Solution::shortestDistance(in_1_m, in_1_s, in_1_d) != 12) {
    throw std::runtime_error("error 1");
  }
  if (Solution::shortestDistance(in_2_m, in_2_s, in_2_d) != -1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
