//
// Created by Lu, Chih-chiang on 2018-12-29.
//

/**
 * Find All Numbers Disappeared in an Array
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    std::vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int idx = std::abs(nums[i]) - 1;
      if (nums[idx] > 0) {
        nums[idx] = -nums[idx];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {4, 3, 2, 7, 8, 2, 3, 1};
  std::vector<int> out = {5, 6};

  if (Solution::findDisappearedNumbers(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
