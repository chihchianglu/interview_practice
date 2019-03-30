//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Search in Rotated Sorted Array II
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Write a function to determine if a given target is in the array.
 *
 * The array may contain duplicates.
 */

#include <vector>
#include <stdexcept>

// issue: [3, 1, 1] or [1, 1, 3, 1]
class Solution {
 public:
  static bool search(std::vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) {
      return false;
    }
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return true;
      } else if (nums[mid] < nums[r]) {
        if (nums[mid] < target && nums[r] >= target) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } else if (nums[mid] > nums[r]) {
        if (nums[mid] > target && nums[l] <= target) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        --r; // skip the duplicate number on 1 side(right side)
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 5, 6, 0, 0, 1, 2};
  if (!Solution::search(vec, 0)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::search(vec, 3)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
