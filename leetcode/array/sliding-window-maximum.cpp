//
// Created by Lu, Chih-chiang on 2019-01-05.
//

/**
 * Sliding Window Maximum
 *
 * Given an array nums, there is a sliding window of size k which is moving from
 * the very left of the array to the very right. You can only see the k numbers
 * in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.
 *
 * Example:
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
 *
 * Follow up:
 * Could you solve it in linear time?
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> res;
    std::deque<int> window;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      // update sliding window size by popping smallest index in the front
      if (!window.empty() && window.front() == i - k) {
        window.pop_front();
      }
      // the 1st element in window is the biggest
      while (!window.empty() && nums[window.back()] < nums[i]) {
        window.pop_back();
      }
      // push cur element
      window.push_back(i);
      // push the 1st element in window -> it's already the biggest
      if (i >= k - 1) {
        res.push_back(nums[window.front()]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
  std::vector<int> out = {3, 3, 5, 5, 6, 7};
  if (Solution::maxSlidingWindow(vec, 3) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
