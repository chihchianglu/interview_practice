//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Largest Number At Least Twice of Others
 *
 * In a given integer array nums, there is always exactly one largest element.
 *
 * Find whether the largest element in the array is at least twice as much as every other number in the array.
 *
 * If it is, return the index of the largest element, otherwise return -1.
 *
 * Example 1:
 *
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 *
 *
 * Example 2:
 *
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int dominantIndex(std::vector<int> &nums) {
    int n = nums.size(), max_idx = 0, first = nums[0], second = std::numeric_limits<int>::min();
    for (int i = 1; i < n; ++i) {
      if (nums[i] >= first) {
        second = first;
        first = nums[i];
        max_idx = i;
      } else if (nums[i] >= second) {
        second = nums[i];
      }
    }
    return first >= 2 * second ? max_idx : -1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 6, 1, 0};
  std::vector<int> vec2 = {1, 2, 3, 4};
  if (Solution::dominantIndex(vec1) != 1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::dominantIndex(vec2) != -1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
