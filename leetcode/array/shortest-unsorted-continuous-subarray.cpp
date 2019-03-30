//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Shortest Unsorted Continuous Subarray
 *
 * Given an integer array, you need to find one continuous subarray that
 * if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 *
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 *
 * Note:
 *
 * - Then length of the input array is in range [1, 10,000].
 * - The input array may contain duplicates, so ascending order here means <=.
 */

#include <vector>
#include <stdexcept>

// 我们新一个跟原数组一摸一样的数组，然后排序。从数组起始位置开始，两个数组相互比较，当对应位置数字不同的时候停止，
// 同理再从末尾开始，对应位置上比较，也是遇到不同的数字时停止，这样中间一段就是最短无序连续子数组了
class Solution {
 public:
  static int findUnsortedSubarray(std::vector<int> &nums) {
    int n = nums.size(), start = -1, end = -2, mn = nums[n - 1], mx = nums[0];
    for (int i = 1; i < n; ++i) {
      mx = std::max(mx, nums[i]);
      mn = std::min(mn, nums[n - 1 - i]);
      if (mx > nums[i]) {
        end = i;
      }
      if (mn < nums[n - 1 - i]) {
        start = n - 1 - i;
      }
    }
    return end - start + 1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 6, 4, 8, 10, 9, 15};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  std::vector<int> vec3 = {5, 4, 3, 2, 1};
  std::vector<int> vec4 = {1, 3, 5, 4, 2};

  if (Solution::findUnsortedSubarray(vec1) != 5) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findUnsortedSubarray(vec2) != 0) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findUnsortedSubarray(vec3) != 5) {
    throw std::runtime_error("error 3");
  }
  if (Solution::findUnsortedSubarray(vec4) != 4) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
