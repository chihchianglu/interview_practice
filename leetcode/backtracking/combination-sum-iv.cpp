//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Combination Sum IV
 *
 * Given an integer array with all positive numbers and no duplicates,
 * find the number of possible combinations that add up to a positive integer target.
 *
 * Example:
 *
 * nums = [1, 2, 3]
 * target = 4
 *
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 *
 * Note that different sequences are counted as different combinations.
 *
 * Therefore the output is 7.
 *
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int combinationSum4(std::vector<int> &nums, int target) {
    if (target == 0) {
      return 1;
    }

    int res = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (target >= nums[i]) {
        res += combinationSum4(nums, target - nums[i]);
      }
    }

    return res;
  }
  // 这道题的真正解法应该是用DP来做，解题思想有点像之前爬梯子的那道题Climbing Stairs，我们需要一个一维数组dp，
  // 其中dp[i]表示目标数为i的解的个数，然后我们从1遍历到target，对于每一个数i，遍历nums数组，
  // 如果i>=x, dp[i] += dp[i - x]。这个也很好理解，比如说对于[1,2,3] 4，这个例子，当我们在计算dp[3]的时候，3可以拆分为1+x，
  // 而x即为dp[2]，3也可以拆分为2+x，此时x为dp[1]，3同样可以拆为3+x，此时x为dp[0]，我们把所有的情况加起来就是组成3的所有情况了
  static int combinationSum4_v2(std::vector<int> &nums, int target) {
    std::vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (auto num : nums) {
        if (i >= num) {
          dp[i] += dp[i - num]; // all the combinations to reach target
        }
      }
    }
    return dp.back();
  }
  static int combinationSum4_v3(std::vector<int> &nums, int target) {
    std::vector<int> dp(target + 1);
    dp[0] = 1;
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i <= target; ++i) {
      for (auto num : nums) {
        if (i < num) {
          break;
        }
        dp[i] += dp[i - num]; // all the combinations to reach target
      }
    }
    return dp.back();
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 1, 3};
  if (Solution::combinationSum4_v2(vec, 35) != 1132436852) {
    throw std::runtime_error("error");
  }
  return 0;
}
