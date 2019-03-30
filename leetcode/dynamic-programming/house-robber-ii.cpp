//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * House Robber II
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
 * stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two
 * adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
 * money you can rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 * Example 2:
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 */

#include <vector>
#include <stdexcept>

// 这道题是之前那道 House Robber 的拓展，现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，
// 所以第一家和最后一家只能抢其中的一家，或者都不抢，那我们这里变通一下，如果我们把第一家和最后一家分别去掉，
// 各算一遍能抢的最大值，然后比较两个值取其中较大的一个即为所求。那我们只需参考之前的 House Robber 中的解题方法，然后调用两边取较大值
class Solution {
 public:
  static int rob(std::vector<int> &nums, int left, int right) {
    if (right - left <= 1) {
      return nums[left];
    }
    std::vector<int> dp(right, 0);
    dp[left] = nums[left];
    dp[left + 1] = std::max(nums[left], nums[left + 1]);
    for (int i = left + 2; i < right; ++i) {
      dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp.back();
  }
  static int rob(std::vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return n ? nums[0] : 0;
    }
    return std::max(rob(nums, 0, n - 1), rob(nums, 1, n));
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec_1{2, 3, 2};
  std::vector<int> vec_2{1, 2, 3, 1};
  if (Solution::rob(vec_1) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::rob(vec_2) != 4) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
