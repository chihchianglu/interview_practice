//
// Created by Lu, Chih-chiang on 2019-03-14.
//

/**
 * Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the
 * bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 * Input: m = 3, n = 2
 * Output: 3
 *
 * Explanation:
 *
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 * Example 2:
 *
 * Input: m = 7, n = 3
 * Output: 28
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // 一行一行update, 也可以用dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
  static int uniquePaths(int m, int n) {
    std::vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
//    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
//    for (int i = 1; i < m; ++i) {
//      for (int j = 1; j < n; ++j) {
//        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//      }
//    }
//    return dp[m - 1][n - 1];
  }
};

int main(int argc, char *argv[]) {
  if (Solution::uniquePaths(3, 2) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::uniquePaths(7, 3) != 28) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
