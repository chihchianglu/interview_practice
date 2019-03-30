//
// Created by Lu, Chih-chiang on 2019-03-15.
//

/**
 * Triangle
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers
 * on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of
 * rows in the triangle.
 */

#include <vector>
#include <stdexcept>

// 在网上搜到一种更好的DP方法，这种方法复制了三角形最后一行，作为用来更新的一位数组。然后逐个遍历这个DP数组，对于每个数字，
// 和它之后的元素比较选择较小的再加上面一行相邻位置的元素做为新的元素，然后一层一层的向上扫描，整个过程和冒泡排序的原理差不多，
// 最后最小的元素都冒到前面，第一个元素即为所求。
class Solution {
 public:
  static int minimumTotal(std::vector<std::vector<int>> &triangle) {
    std::vector<int> dp(triangle.back());
    int rows = triangle.size();
    for (int i = rows - 2; i >= 0; --i) { // 從倒數第二row開始往上查
      for (int j = 0; j <= i; ++j) { // 相鄰位置
        dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    return dp[0];
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  if (Solution::minimumTotal(vec) != 11) {
    throw std::runtime_error("error");
  }
  return 0;
}
