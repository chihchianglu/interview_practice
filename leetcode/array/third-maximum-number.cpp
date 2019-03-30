//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Third Maximum Number
 *
 * Given a non-empty array of integers, return the third maximum number in this array.
 * If it does not exist, return the maximum number. The time complexity must be in O(n).
 *
 * Example 1:
 *
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 *
 * Example 2:
 *
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 *
 * Example 3:
 *
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 */

#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int thirdMax(std::vector<int> &nums) {
    int64_t first = std::numeric_limits<int64_t>::min(), second = std::numeric_limits<int64_t>::min(),
        third = std::numeric_limits<int64_t>::min();

    for (int num : nums) {
      if (num == first || num == second || num == third) {
        continue;
      }
      if (num > first) {
        third = second;
        second = first;
        first = num;
      } else if (num > second) {
        third = second;
        second = num;
      } else if (num > third) {
        third = num;
      }
    }
    return third == std::numeric_limits<int64_t>::min() ? first : third;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 2, 1};
  std::vector<int> vec2 = {1, 2};
  std::vector<int> vec3 = {2, 2, 3, 1};
  if (Solution::thirdMax(vec1) != 1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::thirdMax(vec2) != 2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::thirdMax(vec3) != 1) {
    throw std::runtime_error("error 3");
  }
  return 0;
}