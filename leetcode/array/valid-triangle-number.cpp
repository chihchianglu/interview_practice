//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Valid Triangle Number
 *
 * Given an array consists of non-negative integers, your task is to count the number of triplets
 * chosen from the array that can make triangles if we take them as side lengths of a triangle.
 *
 * Example 1:
 * Input: [2,2,3,4]
 * Output: 3
 *
 * Explanation:
 * Valid combinations are:
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 *
 * Note:
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

class Solution {
 public:
  static int triangleNumber(std::vector<int> &nums) {
    int res = 0, n = nums.size();
    std::sort(nums.begin(), nums.end());

    for (int i = n - 1; i >= 2; --i) {
      int left = 0, right = i - 1;
      while (left < right) {
        if (nums[left] + nums[right] > nums[i]) {
          res += right - left;
          --right;
        } else {
          ++left;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 2, 3, 4};
  if (Solution::triangleNumber(vec) != 3) {
    throw std::runtime_error("error");
  }
  return 0;
}
