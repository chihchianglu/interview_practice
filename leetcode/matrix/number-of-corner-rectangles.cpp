//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Number Of Corner Rectangles
 *
 * Given a grid where each entry is only 0 or 1, find the number of corner rectangles.
 *
 * A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle.
 * Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.
 *
 * Example 1:
 *
 * Input: grid =
 * [[1, 0, 0, 1, 0],
 *  [0, 0, 1, 0, 1],
 *  [0, 0, 0, 1, 0],
 *  [1, 0, 1, 0, 1]]
 *
 * Output: 1
 * Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
 *
 *
 * Example 2:
 *
 * Input: grid =
 * [[1, 1, 1],
 *  [1, 1, 1],
 *  [1, 1, 1]]
 *
 * Output: 9
 * Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
 *
 *
 * Example 3:
 *
 * Input: grid =
 * [[1, 1, 1, 1]]
 *
 * Output: 0
 * Explanation: Rectangles must have four distinct corners.
 *
 * Note:
 *
 * The number of rows and columns of grid will each be in the range [1, 200].
 * Each grid[i][j] will be either 0 or 1.
 * The number of 1s in the grid will be at most 6000.
 */

#include <vector>
#include <stdexcept>

// 我们来看一种优化了时间复杂度的方法，这种方法的原理是两行同时遍历，如果两行中相同列位置的值都为1，则计数器cnt自增1，
// 那么最后就相当于有了(cnt - 1)个相邻的格子，问题就转化为了求cnt-1个相邻的格子能组成多少个矩形，就变成了初中数学问题了，
// 共有cnt*(cnt-1)/2个
class Solution {
 public:
  static int countCornerRectangles(std::vector<std::vector<int>> &grid) {
    int rows = grid.size(), cols = rows ? grid[0].size() : 0, res = 0;
    if (rows == 0 || cols == 0) {
      return res;
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = i + 1; j < rows; ++j) {
        int count = 0;
        for (int k = 0; k < cols; ++k) {
          if (grid[i][k] == 1 && grid[j][k] == 1) {
            ++count;
          }
        }
        // C(n, 2) = n! / (n - 2)! 2!
        res += count * (count - 1) / 2;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec1 = {{1, 0, 0, 1, 0}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {1, 0, 1, 0, 1}};
  std::vector<std::vector<int>> vec2 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> vec3 = {{1, 1, 1, 1}};

  if (Solution::countCornerRectangles(vec1) != 1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::countCornerRectangles(vec2) != 9) {
    throw std::runtime_error("error 2");
  }
  if (Solution::countCornerRectangles(vec3) != 0) {
    throw std::runtime_error("error 3");
  }

  return 0;
}
