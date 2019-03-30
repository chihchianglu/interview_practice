//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example:
 * Input: [2,3,1,1,4]
 * Output: 2
 *
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Note:
 * You can assume that you can always reach the last index.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // prev position: means the current step could reach
  // cur position: means the next step could reach
  static int jump(std::vector<int> &nums) {
    int res = 0, prev = 0, cur = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i > prev) {
        prev = cur;
        ++res;
      }
      cur = std::max(cur, i + nums[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 3, 1, 1, 4};
  if (Solution::jump(vec1) != 2) {
    throw std::runtime_error("error 1");
  }
  return 0;
  return 0;
}
