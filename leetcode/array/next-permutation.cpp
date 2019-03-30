//
// Created by Lu, Chih-chiang on 2019-01-02.
//

/**
 * Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

// 127431 -> 131247
// 那么是如何得到的呢，我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，
// 然后我们再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：
// 127431
// 127431
// 137421
// 131247
class Solution {
 public:
  static void nextPermutation(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i + 1] > nums[i]) {
        for (int j = n - 1; j > i; --j) {
          if (nums[j] > nums[i]) {
            std::swap(nums[i], nums[j]);
            break;
          }
        }
        std::reverse(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    std::reverse(nums.begin(), nums.end());
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 7, 4, 3, 1};
  std::vector<int> vec2 = {9, 9, 7, 1};
  std::vector<int> out1 = {1, 3, 1, 2, 4, 7};
  std::vector<int> out2 = {1, 7, 9, 9};
  Solution::nextPermutation(vec1);
  if (vec1 != out1) {
    throw std::runtime_error("error 1");
  }
  Solution::nextPermutation(vec2);
  if (vec2 != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
