//
// Created by Lu, Chih-chiang on 2018-12-27.
//

/**
 * Max Contiguous Array with Equal Number of 0 and 1
 *
 * Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
 *
 * Example 1:
 *
 * Input: [0,1]
 * Output: 2
 *
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
 *
 * Example 2:
 *
 * Input: [0,1,0]
 * Output: 2
 *
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 *
 * Note: The length of the given binary array will not exceed 50,000.
 */

#include <cmath>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static int findMaxLength(std::vector<int> &nums) {
    int res = 0, n = nums.size(), sum = 0;
    std::unordered_map<int, int> cache{{0, -1}}; // sum -> index
    for (int i = 0; i < n; ++i) {
      sum += (nums[i] == 1) ? 1 : -1;
      if (cache.count(sum)) {
        res = std::max(res, i - cache[sum]);
      } else {
        cache[sum] = i;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  if (Solution::findMaxLength(vec) != 12) {
    throw std::runtime_error("error");
  }
  return 0;
}
