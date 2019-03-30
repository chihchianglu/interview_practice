//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Majority Elements
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears
 * more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Example 1:
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // 1. hash
  // 2. sort & mid index
  // 3. moore voting algorithm to find majority elements if there exists one
  static int majorityElement(std::vector<int> &nums) {
    int res = 0, cnt = 0;
    for (int num : nums) {
      if (cnt == 0) {
        res = num;
        ++cnt;
      } else {
        if (num == res) {
          ++cnt;
        } else {
          --cnt;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 2, 3};
  std::vector<int> vec2 = {2, 2, 1, 1, 1, 2, 2};
  if (Solution::majorityElement(vec1) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::majorityElement(vec2) != 2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
