//
// Created by Lu, Chih-chiang on 2018-12-27.
//

/**
 * Continuous Subarray Sum
 *
 * Given a list of non-negative numbers and a target integer k, write a function to check if the array
 * has a continuous subarray of size at least 2 that sums up to the multiple of k, that is,
 * sums up to n*k where n is also an integer.
 *
 * Example 1:
 *
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 *
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
 *
 * Example 2:
 *
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 *
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 *
 * Note:
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
 */

#include <cmath>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static bool checkSubarraySum_brute_force(std::vector<int> &nums, int k) {
    for (int i = 0; i < nums.size(); ++i) {
      int sum = nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        sum += nums[j];
        if (sum == k) {
          return true;
        }
        if (k != 0 && sum % k == 0) {
          return true;
        }
      }
    }
    return false;
  }

  // a % c = t
  // b % c = t
  // -> (a - b) % c = 0
  static bool checkSubarraySum(std::vector<int> &nums, int k) {
    int n = nums.size(), sum = 0;
    std::unordered_map<int, int> cache{{0, -1}}; // for {0, 0}, k = 0
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      sum = (k == 0) ? sum : (sum % k);
      if (cache.find(sum) != cache.end()) {
        if (i - cache[sum] > 1) {
          return true;
        }
      } else {
        cache[sum] = i;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {23, 2, 4, 6, 7};
  std::vector<int> vec2 = {23, 2, 6, 4, 7};
  if (!Solution::checkSubarraySum_brute_force(vec1, 6)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::checkSubarraySum_brute_force(vec2, 6)) {
    throw std::runtime_error("error 2");
  }
  if (!Solution::checkSubarraySum(vec1, 6)) {
    throw std::runtime_error("error 3");
  }
  if (!Solution::checkSubarraySum(vec2, 6)) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
