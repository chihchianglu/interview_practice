//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Product of Three Numbers
 *
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 *
 * Example 1:
 * Input: [1,2,3]
 * Output: 6
 *
 * Example 2:
 * Input: [1,2,3,4]
 * Output: 24
 *
 * Note:
 * The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 */

#include <limits>
#include <vector>
#include <algorithm>
#include <stdexcept>

// max:
// 1. [-100, -10, 1, 2, 8] -> mn1 * mn2 * mx1
// 2. [1, 2, 3, 4, 5] -> mx1 * mx2 * mx3
class Solution {
 public:
  // O(nlogn)
  static int maximumProduct_sort(std::vector<int> &nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    return std::max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
  }
  // O(n)
  static int maximumProduct(std::vector<int> &nums) {
    int mx1 = std::numeric_limits<int>::min(), mx2 = std::numeric_limits<int>::min(),
        mx3 = std::numeric_limits<int>::min();
    int mn1 = std::numeric_limits<int>::max(), mn2 = std::numeric_limits<int>::max();
    for (int num : nums) {
      if (num > mx1) {
        mx3 = mx2;
        mx2 = mx1;
        mx1 = num;
      } else if (num > mx2) {
        mx3 = mx2;
        mx2 = num;
      } else if (num > mx3) {
        mx3 = num;
      }
      if (num < mn1) {
        mn2 = mn1;
        mn1 = num;
      } else if (num < mn2) {
        mn2 = num;
      }
    }
    return std::max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3, 4};
  if (Solution::maximumProduct_sort(vec1) != 6) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maximumProduct_sort(vec2) != 24) {
    throw std::runtime_error("error 2");
  }
  if (Solution::maximumProduct(vec1) != 6) {
    throw std::runtime_error("error 3");
  }
  if (Solution::maximumProduct(vec2) != 24) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
