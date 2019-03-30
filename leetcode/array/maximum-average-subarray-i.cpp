//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Average Subarray I
 *
 * Given an array consisting of n integers, find the contiguous subarray of given length k
 * that has the maximum average value. And you need to output the maximum average value.
 *
 * Example 1:
 *
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 *
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 * Note:
 *
 * - 1 <= k <= n <= 30,000.
 * - Elements of the given array will be in the range [-10,000, 10,000].
 */

#include <vector>
#include <numeric>
#include <stdexcept>

class Solution {
 public:
  static double findMaxAverage(std::vector<int> &nums, int k) {
    double sum = std::accumulate(nums.begin(), nums.begin() + k, 0), n = nums.size(), res = sum;
    for (int i = k; i < n; ++i) {
      sum += nums[i] - nums[i - k];
      res = std::max(res, sum);
    }
    return res / k;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 12, -5, -6, 50, 3};
  if (Solution::findMaxAverage(vec, 4) != 12.75) {
    throw std::runtime_error("error");
  }
  return 0;
}
