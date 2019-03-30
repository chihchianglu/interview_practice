//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Max Consecutive Ones II
 *
 * Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
 *
 * Example 1:
 * Input: [1,0,1,1,0]
 * Output: 4
 *
 * Explanation:
 * Flip the first zero will get the the maximum number of consecutive 1s.
 * After flipping, the maximum number of consecutive 1s is 4.
 *
 * Note:
 *
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 * Follow up:
 * What if the input numbers come in one by one as an infinite stream?
 * In other words, you can't store all  * numbers coming from the stream as it's too large
 * to hold in memory. Could you solve it efficiently?
 *
 * Solution:
 * The idea is to keep a window [l, h] that contains at most k zero
 */

#include <cmath>
#include <queue>
#include <vector>

class Solution {
 public:
  // only work for flip 1 zero
  static int findMaxConsecutiveOnes_v1(std::vector<int> &nums) {
    int res = 0, cur = 0, cnt = 0;
    for (int num : nums) {
      ++cnt;
      if (num == 0) {
        cur = cnt;
        cnt = 0;
      }
      res = std::max(res, cnt + cur);
    }
    return res;
  }
  // work for fliping k zeros, but not work for follow-up
  // Time: O(n) Space: O(1)
  static int findMaxConsecutiveOnes_v2(std::vector<int> &nums) {
    int res = 0, zero = 0, left = 0, n = nums.size();
    int k = 1; // flip at most k zero

    for (int right = 0; right < n; ++right) {
      if (nums[right] == 0) {
        ++zero;
      }
      while (zero > k) {
        if (nums[left++] == 0) {
          --zero;
        }
      }
      res = std::max(res, right - left + 1);
    }
    return res;
  }
  // work for everything
  // Time: O(n) Space: O(k)
  static int findMaxConsecutiveOnes(std::vector<int> &nums) {
    int res = 0, left = 0, n = nums.size();
    int k = 1; // flip at most k zero
    std::queue<int> zero;
    for (int right = 0; right < n; ++right) {
      if (nums[right] == 0) {
        zero.push(right);
      }
      if (zero.size() > k) {
        left = zero.front() + 1;
        zero.pop();
      }
      res = std::max(res, right - left + 1);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 0, 1, 1, 0};
  if (Solution::findMaxConsecutiveOnes_v1(vec) != 4) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findMaxConsecutiveOnes_v2(vec) != 4) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findMaxConsecutiveOnes(vec) != 4) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
