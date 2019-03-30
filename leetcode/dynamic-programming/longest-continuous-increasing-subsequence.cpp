//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Longest Continuous Increasing Subsequence
 *
 * Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 *
 * Example 1:
 *
 * Input: [1,3,5,4,7]
 * Output: 3
 *
 * Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 * Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
 *
 * Example 2:
 *
 * Input: [2,2,2,2,2]
 * Output: 1
 *
 * Explanation: The longest continuous increasing subsequence is [2], its length is 1.
 *
 * Note: Length of the array will not exceed 10,000.
 */

#include <vector>
#include <numeric>
#include <stdexcept>

class Solution {
 public:
  static int findLengthOfLCIS(std::vector<int> &nums) {
    int res = 1, cnt = 1, n = nums.size();
    if (n == 0) {
      return 0;
    }
    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1]) {
        ++cnt;
        res = std::max(res, cnt);
      } else {
        cnt = 1;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec_1{1, 3, 5, 4, 7};
  std::vector<int> vec_2{2, 2, 2, 2, 2};
  if (Solution::findLengthOfLCIS(vec_1) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findLengthOfLCIS(vec_2) != 1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
