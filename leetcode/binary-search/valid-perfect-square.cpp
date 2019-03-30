//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Valid Perfect Square
 *
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 * Input: 16
 * Output: true
 * Example 2:
 *
 * Input: 14
 * Output: false
 */

#include <stdexcept>

class Solution {
 public:
  static bool isPerfectSquare(int num) {
    int l = 0, r = num;
    while (l <= r) {
      int64_t mid = (l + r) / 2, target = mid * mid;
      if (target == num) {
        return true;
      } else if (target < num) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::isPerfectSquare(16)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::isPerfectSquare(14)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
