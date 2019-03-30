//
// Created by Lu, Chih-chiang on 2018-12-27.
//

/**
 * Contains Duplicate II
 *
 * Given an array of integers and an integer k, find out whether there are two distinct
 * indices i and j in the array such that nums[i] = nums[j] and the absolute difference
 * between i and j is at most k.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * Example 2:
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * Example 3:
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  // find out a duplicate && the index diff of duplicate must <= k
  static bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> lookup_table;
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      auto found = lookup_table.find(num);
      if (found != lookup_table.end() && i - found->second <= k) {
        return true;
      } else {
        lookup_table[num] = i;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 3, 1};
  std::vector<int> vec2 = {1, 0, 1, 1};
  std::vector<int> vec3 = {1, 2, 3, 1, 2, 3};
  if (!Solution::containsNearbyDuplicate(vec1, 3)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::containsNearbyDuplicate(vec2, 1)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::containsNearbyDuplicate(vec3, 2)) {
    throw std::runtime_error("error 3");
  }

  return 0;
}
