//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Wiggle Sort II
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 *
 * Example 1:
 *
 * Input: nums = [1, 5, 1, 1, 6, 4]
 * Output: One possible answer is [1, 4, 1, 5, 1, 6].
 *
 * Example 2:
 *
 * Input: nums = [1, 3, 2, 2, 3, 1]
 * Output: One possible answer is [2, 3, 1, 3, 1, 2].
 *
 * Note:
 * You may assume all input has valid answer.
 *
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

class Solution {
 public:
  // O(n) space
  static void wiggleSort_v1(std::vector<int> &nums) {
    std::vector<int> tmp = nums;
    int n = nums.size(), j = (n + 1) / 2, k = n;
    std::sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; ++i) {
      nums[i] = i & 1 ? tmp[--k] : tmp[--j];
    }
  }

  // O(1) space
  static void wiggleSort(std::vector<int> &nums) {
    int n = nums.size();

    // find a median
    auto midptr = nums.begin() + n / 2;
    std::nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // index mapping
#define A(i) nums[(1 + 2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
      if (A(j) > mid) {
        std::swap(A(i++), A(j++));
      } else if (A(j) < mid) {
        std::swap(A(j), A(k--));
      } else {
        j++;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 5, 1, 1, 6, 4};
  std::vector<int> vec2 = {1, 3, 2, 2, 3, 1};
  std::vector<int> vec3 = {1, 5, 1, 1, 6, 4};
  std::vector<int> vec4 = {1, 3, 2, 2, 3, 1};
  std::vector<int> out1 = {1, 6, 1, 5, 1, 4};
  std::vector<int> out2 = {2, 3, 1, 3, 1, 2};
  std::vector<int> out3 = {1, 5, 1, 6, 1, 4};
  std::vector<int> out4 = {2, 3, 1, 3, 1, 2};

  Solution::wiggleSort_v1(vec1);
  Solution::wiggleSort_v1(vec2);
  if (vec1 != out1) {
    throw std::runtime_error("error 1");
  }
  if (vec2 != out2) {
    throw std::runtime_error("error 2");
  }
  Solution::wiggleSort(vec3);
  Solution::wiggleSort(vec4);
  if (vec3 != out3) {
    throw std::runtime_error("error 3");
  }
  if (vec4 != out4) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
