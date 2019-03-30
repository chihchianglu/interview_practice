//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Product Subarray
 *
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has
 * the largest product.
 *
 * Example 1:
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 * Example 2:
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int maxProduct(std::vector<int> &nums) {
    int res = nums[0], mx = res, mn = res, n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] < 0) {
        std::swap(mn, mx);
      }
      mx = std::max(mx * nums[i], nums[i]);
      mn = std::min(mn * nums[i], nums[i]);
      res = std::max(res, mx);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 3, -2, 4};
  std::vector<int> vec2 = {-2, 0, -1};
  if (Solution::maxProduct(vec1) != 6) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxProduct(vec2) != 0) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
