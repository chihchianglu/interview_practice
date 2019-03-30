//
// Created by Lu, Chih-chiang on 2019-03-15.
//

/**
 * Target Sum
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
 * Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 *
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 *
 * Example 1:
 *
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 *
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 *
 * Note:
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static void helper(std::vector<int> &nums, int64_t S, int start, int &res) {
    if (start >= nums.size()) {
      if (S == 0) {
        ++res;
      }
      return;
    }
    helper(nums, S - nums[start], start + 1, res);
    helper(nums, S + nums[start], start + 1, res);
  }
  static int findTargetSumWays(std::vector<int> &nums, int S) {
    int res = 0;
    helper(nums, S, 0, res);
    return res;
  }

  // use dp to cache already calculated number
  static int helper_dp(std::vector<int> &nums, int64_t S, int start, std::vector<std::unordered_map<int, int>> &dp) {
    if (start == nums.size()) {
      return S == 0;
    } else if (dp[start].count(S)) {
      return dp[start][S];
    }
    int count1 = helper_dp(nums, S - nums[start], start + 1, dp);
    int count2 = helper_dp(nums, S + nums[start], start + 1, dp);
    int res = count1 + count2;
    dp[start][S] = count1 + count2;
    return res;
  }
  static int findTargetSumWays_dp(std::vector<int> &nums, int S) {
    std::vector<std::unordered_map<int, int>> dp(nums.size());
    return helper_dp(nums, S, 0, dp);
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec{1, 1, 1, 1, 1};
  if (Solution::findTargetSumWays(vec, 3) != 5) {
    throw std::runtime_error("error");
  }
  return 0;
}
