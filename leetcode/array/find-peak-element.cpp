//
// Created by Lu, Chih-chiang on 2018-12-29.
//

/**
 * Find Peak Element
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */

#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int findPeakElement(std::vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }
    nums.insert(nums.begin(), std::numeric_limits<int32_t>::min());
    nums.push_back(std::numeric_limits<int32_t>::min());
    n += 2;
    for (int i = 1; i < n - 1; i++) {
      if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i]) {
        return i - 1;
      }
    }
    return -1;
  }
  static int findPeakElement_optimize(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        return i - 1;
      }
    }
    return nums.size() - 1;
  }
  static int findPeakElement_log(std::vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[mid + 1]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3, 1};
  if (Solution::findPeakElement_optimize(vec) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findPeakElement_log(vec) != 2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findPeakElement(vec) != 2) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
