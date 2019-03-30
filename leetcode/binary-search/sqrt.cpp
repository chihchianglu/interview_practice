//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Sqrt(x)
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is
 * returned.
 *
 * Example 1:
 *
 * Input: 4
 * Output: 2
 *
 * Example 2:
 *
 * Input: 8
 * Output: 2
 *
 * Explanation: The square root of 8 is 2.82842..., and since
 *              the decimal part is truncated, 2 is returned.
 */

#include <stdexcept>

class Solution {
 public:
  static int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    int l = 0, r = x;
    while (l < r) {
      int mid = (l + r) / 2;
      if (x / mid >= mid) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return r - 1;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::mySqrt(4) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::mySqrt(8) != 2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
