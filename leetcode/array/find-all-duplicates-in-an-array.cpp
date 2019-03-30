//
// Created by Lu, Chih-chiang on 2018-12-28.
//

/**
 * Find All Duplicates in an Array
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> findDuplicates(std::vector<int> &nums) {
    std::vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      int idx = std::abs(nums[i]) - 1;
      if (nums[idx] < 0) {
        res.push_back(idx + 1);
      }
      nums[idx] = -nums[idx];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {4, 3, 2, 7, 8, 2, 3, 1};
  std::vector<int> out = {2, 3};

  if (Solution::findDuplicates(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
