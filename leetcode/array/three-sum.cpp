//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Three Sum
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique
 * triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
class Solution {
 public:
  static std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n == 0 || nums[0] > 0 || nums.back() < 0) {
      return {};
    }

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] > 0) {
        break;
      }

      // Avoid duplication
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int target = 0 - nums[i];
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int k = nums[left] + nums[right];
        if (k == target) {
          res.push_back({nums[i], nums[left], nums[right]});

          // Skip duplication
          while (left < right && nums[left] == nums[left + 1]) {
            ++left;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            --right;
          }

          ++left;
          --right;
        } else if (k > target) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> out = {{-1, -1, 2}, {-1, 0, 1}};
  if (Solution::threeSum(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
