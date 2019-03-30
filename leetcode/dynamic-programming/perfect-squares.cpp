//
// Created by Lu, Chih-chiang on 2019-03-15.
//

/**
 * Perfect Squares
 *
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * Example 2:
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

#include <vector>
#include <numeric>
#include <stdexcept>

// 我们可以用动态规划Dynamic Programming来做，我们建立一个长度为n+1的一维dp数组，将第一个值初始化为0，其余值都初始化为INT_MAX,
// i从1循环到n，j从1循环到j*j <= i的位置，然后每次更新dp[i]的值，动态更新dp数组，其中dp[i]表示正整数i至少能由多个完全平方数组成，
// 那么我们求n，就是返回dp[n]即可，也就是dp数组的最后一个数字。
class Solution {
 public:
  static int numSquares(int n) {
    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = std::min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp.back();
  }
};

int main(int argc, char *argv[]) {
  if (Solution::numSquares(12) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::numSquares(13) != 2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
