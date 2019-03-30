//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Subarray
 *
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum
 * and return its sum.
 *
 * Example:
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 *
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which
 * is more subtle.
 */

#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int maxSubArrayLen(std::vector<int> &nums) {
    int res = std::numeric_limits<int>::min(), cur_sum = 0;
    for (int num : nums) {
      cur_sum = std::max(cur_sum + num, num);
      res = std::max(res, cur_sum);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  if (Solution::maxSubArrayLen(vec) != 6) {
    throw std::runtime_error("error");
  }
  return 0;
}
