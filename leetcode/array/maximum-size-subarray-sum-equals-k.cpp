//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Size Subarray Sum Equals k
 *
 * Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
 * If there isn't one, return 0 instead.
 *
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
 *
 * Example 1:
 *
 * Input: nums = [1, -1, 5, -2, 3], k = 3
 * Output: 4
 *
 * Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
 *
 * Example 2:
 *
 * Input: nums = [-2, -1, 2, 1], k = 1
 * Output: 2
 *
 * Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 *
 * Follow Up:
 * Can you do it in O(n) time?
 */

#include <vector>
#include <unordered_map>

class Solution {
 public:
  static int maxSubArrayLen(std::vector<int> &nums, int k) {
    int sum = 0, res = 0, n = nums.size();
    std::unordered_map<int, int> cache = {{0, -1}};

    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      int target = sum - k;
      if (cache.find(target) != cache.end()) {
        res = std::max(res, i - cache[target]);
      }
      if (cache.find(sum) == cache.end()) {
        cache[sum] = i;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, -1, 5, -2, 3};
  std::vector<int> vec2 = {-2, -1, 2, 1};
  if (Solution::maxSubArrayLen(vec1, 3) != 4) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxSubArrayLen(vec2, 1) != 2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
