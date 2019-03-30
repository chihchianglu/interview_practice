//
// Created by Lu, Chih-chiang on 2018-12-27.
//

/**
 * Contains Duplicate III
 *
 * Given an array of integers, find out whether there are two distinct indices i and j in the array
 * such that the absolute difference between nums[i] and nums[j] is at most t and the absolute
 * difference between i and j is at most k.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * Example 2:
 *
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * Example 3:
 *
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 */

#include <map>
#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
    std::map<int, int> lookup_table;
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i - j > k) {
        lookup_table.erase(nums[j++]);
      }
      auto a = lookup_table.lower_bound(nums[i] - t);
      if (a != lookup_table.end() && std::abs(a->first - nums[i]) <= t) {
        return true;
      }
      lookup_table[nums[i]] = i;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 1};
  std::vector<int> vec2 = {1, 0, 1, 1};
  std::vector<int> vec3 = {1, 5, 9, 1, 5, 9};
  if (!Solution::containsNearbyAlmostDuplicate(vec1, 1, 1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::containsNearbyAlmostDuplicate(vec2, 1, 2)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::containsNearbyAlmostDuplicate(vec3, 2, 3)) {
    throw std::runtime_error("error 3");
  }

  return 0;
}
