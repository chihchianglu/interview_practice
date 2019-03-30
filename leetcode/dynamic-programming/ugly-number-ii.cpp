//
// Created by Lu, Chih-chiang on 2019-03-14.
//

/**
 * Ugly Number II
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 *
 * Example:
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Solution
 *
 * The ugly-number sequence is 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
 * because every number can only be divided by 2, 3, 5, one way to look at the sequence is to split
 * the sequence to three groups as below:
 *
 * (1) 1×2, 2×2, 3×2, 4×2, 5×2, ...
 * (2) 1×3, 2×3, 3×3, 4×3, 5×3, ...
 * (3) 1×5, 2×5, 3×5, 4×5, 5×5, ...
 *
 * We can find that every subsequence is the ugly-sequence itself (1, 2, 3, 4, 5, ...) multiply 2, 3, 5.
 *
 * Then we use similar merge method as merge sort, to get every ugly number from the three subsequence.
 *
 * Every step we choose the smallest one, and move one step after,including nums with same value.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int nthUglyNumber(int n) {
    std::vector<int> res(1, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    while (res.size() < n) {
      int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
      int mn = std::min(m2, std::min(m3, m5));
      if (mn == m2) {
        ++i2;
      }
      if (mn == m3) {
        ++i3;
      }
      if (mn == m5) {
        ++i5;
      }
      res.push_back(mn);
    }
    return res.back();
  }
};

int main(int argc, char *argv[]) {
  if (Solution::nthUglyNumber(10) != 12) {
    throw std::runtime_error("error");
  }
  return 0;
}
