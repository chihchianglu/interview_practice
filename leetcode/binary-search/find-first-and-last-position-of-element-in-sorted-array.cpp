//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target
 * value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int searchLowerBound(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        if (mid == 0 || nums[mid] > nums[mid - 1]) {
          return mid;
        } else {
          r = mid - 1;
        }
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
  static int searchUpperBound(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        if (mid == nums.size() - 1 || nums[mid] < nums[mid + 1]) {
          return mid;
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
  static std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int lower = searchLowerBound(nums, target);
    int upper = searchUpperBound(nums, target);
    if (lower == -1) {
      return {-1, -1};
    }
    return {lower, upper};
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {5, 7, 7, 8, 8, 10};
  if (Solution::searchRange(vec, 8) != std::vector<int>{3, 4}) {
    throw std::runtime_error("error 1");
  }
  if (Solution::searchRange(vec, 6) != std::vector<int>{-1, -1}) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
