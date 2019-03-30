//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Power(x, n)
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 *
 * Example 1:
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 * Example 2:
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 * Example 3:
 *
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * Note:
 *
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */

#include <stdexcept>

// 这个题目的难度是中等，所以如果用显而易见的那个O(n)算法，即直接循环n次，将n个x乘起来的话是肯定会超时的，所以，只能用递归分治算法，
// 即一次只乘一半，设值为A，即当n为偶数时，结果是A*A；当n为奇数时，结果为A*A*x；当然，如果n为负数，则计算倒数即可。
// 例：
// 1. 计算pow(2, 4)
// A = pow(2, 2)
// return A * A
//
// 2. 计算pow(2, 5)
// A = pow(2, 5/2) = pow(2, 2)
// return A * A *x
class Solution {
 public:
  static double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    } else if (n == 1) {
      return x;
    } else if (n == -1) {
      return 1.0 / x;
    }
    double tmp = myPow(x, n / 2);
    if (n % 2 == 0) { // even number no matter positive or negative % 2 == 0
      return tmp * tmp;
    } else if (n > 0) {
      return tmp * tmp * x;
    }
    return tmp * tmp / x; // tmp * tmp * 1/x
  }
};

int main(int argc, char *argv[]) {
  if (Solution::myPow(2.00000, 10) != 1024.0f) {
    throw std::runtime_error("error 1");
  }
  double tmp = Solution::myPow(2.10000, 3);
  if (tmp > 9.262f || tmp < 9.260f) {
    throw std::runtime_error("error 2");
  }
  if (Solution::myPow(2.00000, -2) != 0.25f) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
