//
// Created by Lu, Chih-chiang on 2018-12-30.
//

/**
 * K-diff Pairs in an Array
 *
 * Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array.
 * Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their
 * absolute difference is k.
 *
 * Example 1:
 *
 * Input: [3, 1, 4, 1, 5], k = 2
 * Output: 2
 *
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 * Although we have two 1s in the input, we should only return the number of unique pairs.
 *
 * Example 2:
 *
 * Input:[1, 2, 3, 4, 5], k = 1
 * Output: 4
 *
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
 *
 * Example 3:
 *
 * Input: [1, 3, 1, 5, 4], k = 0
 * Output: 1
 *
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static int findPairs_map(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    int res = 0;
    for (int num : nums) {
      ++map[num];
    }
    for (auto &m : map) {
      if (k == 0 && m.second > 1) {
        ++res;
      } else if (k > 0 && map.find(m.first + k) != map.end()) {
        ++res;
      }
    }
    return res;
  }
  static int findPairs(std::vector<int> &nums, int k) {
    int res = 0, n = nums.size(), j = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
      j = std::max(j, i + 1);
      while (j < n && nums[j] - nums[i] < k) {
        ++j;
      }
      if (j < n && nums[j] - nums[i] == k) {
        ++res;
      }
      while (i < n - 1 && nums[i] == nums[i + 1]) {
        ++i;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 1, 4, 1, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  std::vector<int> vec3 = {1, 3, 1, 5, 4};

  if (Solution::findPairs_map(vec1, 2) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findPairs_map(vec2, 1) != 4) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findPairs_map(vec3, 0) != 1) {
    throw std::runtime_error("error 3");
  }

  if (Solution::findPairs(vec1, 2) != 2) {
    throw std::runtime_error("error 4");
  }
  if (Solution::findPairs(vec2, 1) != 4) {
    throw std::runtime_error("error 5");
  }
  if (Solution::findPairs(vec3, 0) != 1) {
    throw std::runtime_error("error 6");
  }

  return 0;
}
