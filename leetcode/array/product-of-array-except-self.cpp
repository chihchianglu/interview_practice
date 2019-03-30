//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Product of Array Except Self
 *
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product
 * of all the elements of nums except nums[i].
 *
 * Example:
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of
 * space complexity analysis.)
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> productExceptSelf_v1(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> fwd(n, 1), bwd(n, 1), res(n, 0);

    for (int i = 0; i < n - 1; ++i) {
      fwd[i + 1] = fwd[i] * nums[i];
    }
    for (int i = n - 1; i > 0; --i) {
      bwd[i - 1] = bwd[i] * nums[i];
    }
    for (int i = 0; i < n; ++i) {
      res[i] = fwd[i] * bwd[i];
    }
    return res;
  }

  static std::vector<int> productExceptSelf(std::vector<int> &nums) {
    int n = nums.size(), accumulate_r = 1;
    std::vector<int> res(n, 1);

    for (int i = 1; i < n; ++i) {
      res[i] = res[i - 1] * nums[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
      res[i] *= accumulate_r;
      accumulate_r *= nums[i];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3, 4};
  std::vector<int> out = {24, 12, 8, 6};

  if (Solution::productExceptSelf_v1(vec) != out) {
    throw std::runtime_error("error 1");
  }
  if (Solution::productExceptSelf(vec) != out) {
    throw std::runtime_error("error 2");
  }
  return 0;
}

