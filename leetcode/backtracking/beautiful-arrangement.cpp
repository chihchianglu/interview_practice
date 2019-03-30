//
// Created by Lu, Chih-chiang on 2019-02-03.
//

/**
 * Beautiful Arrangement
 *
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is
 * constructed by these N numbers successfully if one of the following is true for the ith position
 * (1 <= i <= N) in this array:
 *
 * 1. The number at the ith position is divisible by i.
 * 2. i is divisible by the number at the ith position.
 * Now given N, how many beautiful arrangements can you construct?
 *
 * Example 1:
 *
 * Input: 2
 * Output: 2
 *
 * Explanation:
 *
 * The first beautiful arrangement is [1, 2]:
 *
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 *
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 *
 * The second beautiful arrangement is [2, 1]:
 *
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 *
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 *
 * Note:
 * N is a positive integer and will not exceed 15.
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

class Solution {
 public:
  static int countArrangement(int N) {
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
      nums[i] = i + 1;
    }
    return helper(N, nums);
  }
  // n means:
  // 1. how many numbers left for completion
  // 2. index(i + 1) of the number we want to try
  static int helper(int n, std::vector<int> &nums) {
    if (n <= 0) {
      return 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (n % nums[i] == 0 || nums[i] % n == 0) {
        std::swap(nums[i], nums[n - 1]);
        res += helper(n - 1, nums);
        std::swap(nums[i], nums[n - 1]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::countArrangement(4) != 8) {
    throw std::runtime_error("error");
  }
  return 0;
}
