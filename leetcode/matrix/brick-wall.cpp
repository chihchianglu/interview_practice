//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Brick Wall
 *
 * There is a brick wall in front of you. The wall is rectangular and has several rows of bricks.
 * The bricks have the same height but different width. You want to draw a vertical line from the
 * top to the bottom and cross the least bricks.
 *
 * The brick wall is represented by a list of rows. Each row is a list of integers representing the
 * width of each brick in this row from left to right.
 *
 * If your line go through the edge of a brick, then the brick is not considered as crossed. You need
 * to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
 *
 * You cannot draw a line just along one of the two vertical edges of the wall, in which case the line
 * will obviously cross no bricks.
 *
 * Example:
 *
 * Input:
 * [[1,2,2,1],
 *  [3,1,2],
 *  [1,3,2],
 *  [2,4],
 *  [3,1,2],
 *  [1,3,1,1]]
 * Output: 2
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

// 这道题给了我们一个砖头墙壁，上面由不同的长度的砖头组成，让我们选个地方从上往下把墙劈开，使得被劈开的砖头个数最少，
// 前提是不能从墙壁的两边劈，这样没有什么意义。我们使用一个哈希表来建立每一个断点的长度和其出现频率之间的映射，
// 这样只要我们从断点频率出现最多的地方劈墙，损坏的板砖一定最少
class Solution {
 public:
  static int leastBricks(std::vector<std::vector<int>> &wall) {
    int mx = 0, n = wall.size();
    std::unordered_map<int, int> m;
    for (auto w : wall) {
      int sum = 0, nn = w.size();
      for (int i = 0; i < nn - 1; ++i) {
        sum += w[i];
        ++m[sum];
        mx = std::max(mx, m[sum]);
      }
    }
    return n - mx;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
  if (Solution::leastBricks(wall) != 2) {
    throw std::runtime_error("error");
  }
  return 0;
}
