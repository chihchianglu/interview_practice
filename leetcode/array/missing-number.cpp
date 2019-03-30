//
// Created by Lu, Chih-chiang on 2019-01-02.
//

/**
 * Missing Number
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * Example 1:
 *
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space
 * complexity?
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int missingNumber(std::vector<int> &nums) {
    int sum = 0, n = nums.size();
    for (auto num : nums) {
      sum += num;
    }
    return (n * (n + 1)) / 2 - sum;
  }
  static int missingNumber_xor(std::vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res ^= (i + 1) ^ nums[i];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 0, 1};
  std::vector<int> vec2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  if (Solution::missingNumber(vec1) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::missingNumber(vec2) != 8) {
    throw std::runtime_error("error 2");
  }
  if (Solution::missingNumber_xor(vec1) != 2) {
    throw std::runtime_error("error 3");
  }
  if (Solution::missingNumber_xor(vec2) != 8) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
