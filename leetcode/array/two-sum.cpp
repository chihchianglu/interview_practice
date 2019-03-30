//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Two Sum
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (map.find(target - nums[i]) != map.end()) {
        return {map[target - nums[i]], i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 7, 11, 15};
  std::vector<int> out = {0, 1};
  if (Solution::twoSum(vec, 9) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
