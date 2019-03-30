//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Subarray Product Less Than K
 *
 * Your are given an array of positive integers nums.
 *
 * Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less
 * than k.
 *
 * Example 1:
 *
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 *
 * Explanation: The 8 subarrays that have product less than 100 are:
 * [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 *
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
 */

// skip

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int numSubarrayProductLessThanK(std::vector<int> &nums, int k) {
    int res = 0, product = 1, n = nums.size();

    for (int i = 0, j = 0; j < n; ++j) {
      product *= nums[j];

      while (i <= j && product >= k) {
        product /= nums[i++];
      }
      res += j - i + 1;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {10, 5, 2, 6};
  if (Solution::numSubarrayProductLessThanK(vec, 100) != 8) {
    throw std::runtime_error("error");
  }
  return 0;
}
