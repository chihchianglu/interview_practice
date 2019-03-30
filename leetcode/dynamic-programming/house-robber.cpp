//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * House Robber
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
 * stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
 * money you can rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * Example 2:
 *
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *              Total amount you can rob = 2 + 9 + 1 = 12.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // O(1) space
  static int rob(std::vector<int> &nums) {
    int rob_even = 0, rob_odd = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        rob_even = std::max(rob_even + nums[i], rob_odd);
      } else {
        rob_odd = std::max(rob_odd + nums[i], rob_even);
      }
    }
    return std::max(rob_even, rob_odd);
  }
  // O(n) space
  // 这道题的本质相当于在一列数组中取出一个或多个不相邻数，使其和最大。
  // 那么我们对于这类求极值的问题首先考虑动态规划Dynamic Programming来解，我们维护一个一位数组dp，
  // 其中dp[i]表示到i位置时不相邻数能形成的最大和，那么状态转移方程怎么写呢，我们先拿一个简单的例子来分析一下，
  // 比如说nums为{3, 2, 1, 5}，那么我们来看我们的dp数组应该是什么样的，首先dp[0]=3没啥疑问，再看dp[1]是多少呢，
  // 由于3比2大，所以我们抢第一个房子的3，当前房子的2不抢，所以dp[1]=3，那么再来看dp[2]，由于不能抢相邻的，
  // 所以我们可以用再前面的一个的dp值加上当前的房间值，和当前房间的前面一个dp值比较，取较大值当做当前dp值，
  // 所以我们可以得到状态转移方程dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 由此看出我们需要初始化dp[0]和dp[1]，
  // 其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])
  static int rob_dp(std::vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return nums.empty() ? 0 : nums[0];
    }
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp.back();
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec_1{1, 2, 3, 1};
  std::vector<int> vec_2{2, 7, 9, 3, 1};
  if (Solution::rob(vec_1) != 4) {
    throw std::runtime_error("error 1");
  }
  if (Solution::rob(vec_2) != 12) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
