//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 *
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 *
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 *              jump length is 0, which makes it impossible to reach the last index.
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

class Solution {
 public:
  static bool canJump(std::vector<int> &nums) {
    int n = nums.size(), reach = 0;
    for (int i = 0; i < n; ++i) {
      if (i > reach || i >= n - 1) {
        break;
      }
      reach = std::max(reach, i + nums[i]);
    }
    return reach >= n - 1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 3, 1, 1, 4};
  std::vector<int> vec2 = {3, 2, 1, 0, 4};
  if (!Solution::canJump(vec1)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::canJump(vec2)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
