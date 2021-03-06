//
// Created by Lu, Chih-chiang on 2019-01-03.
//

/**
 * Plus One
 *
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 * Example 2:
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> plusOne(std::vector<int> &digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
      if (digits[i] == 9) {
        digits[i] = 0;
      } else {
        ++digits[i];
        return digits;
      }
    }

    digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {4, 3, 2, 1};
  std::vector<int> vec3 = {9, 9, 9, 9};
  std::vector<int> out1 = {1, 2, 4};
  std::vector<int> out2 = {4, 3, 2, 2};
  std::vector<int> out3 = {1, 0, 0, 0, 0};

  if (Solution::plusOne(vec1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::plusOne(vec2) != out2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::plusOne(vec3) != out3) {
    throw std::runtime_error("error 3");
  }

  return 0;
}
