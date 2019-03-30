//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Wiggle Sort
 *
 * Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

class Solution {
 public:
  // time O(nlogn)
  static void wiggleSort_v1(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n <= 2) {
      return;
    }
    for (int i = 2; i < n; i += 2) {
      std::swap(nums[i], nums[i - 1]);
    }
  }
  // time O(n)
  static void wiggleSort(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if ((i % 2 == 0 && nums[i] > nums[i - 1]) || (i % 2 == 1 && nums[i] < nums[i - 1])) {
        std::swap(nums[i], nums[i - 1]);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 5, 2, 1, 6, 4};
  std::vector<int> vec2 = {3, 5, 2, 1, 6, 4};
  std::vector<int> out1 = {1, 3, 2, 5, 4, 6};
  std::vector<int> out2 = {3, 5, 1, 6, 2, 4};

  Solution::wiggleSort_v1(vec1);
  Solution::wiggleSort(vec2);
  if (vec1 != out1) {
    throw std::runtime_error("error 1");
  }
  if (vec2 != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
