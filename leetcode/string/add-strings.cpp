//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * Add Strings
 *
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 *
 * Note:
 *
 * 1. The length of both num1 and num2 is < 5100.
 * 2. Both num1 and num2 contains only digits 0-9.
 * 3. Both num1 and num2 does not contain any leading zero.
 * 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

#include <string>
#include <stdexcept>

// char +/- char -> integer, ex: 'b' - 'a' -> 1
// integer +/- char -> char, ex: 9 + '0' -> '9'
class Solution {
 public:
  static std::string addStrings(std::string num1, std::string num2) {
    std::string res;
    int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
    while (i >= 0 || j >= 0) {
      int a = i >= 0 ? num1[i--] - '0' : 0;
      int b = j >= 0 ? num2[j--] - '0' : 0;
      int sum = a + b + carry;
      res.insert(res.begin(), sum % 10 + '0');
      carry = sum / 10;
    }
    return carry ? "1" + res : res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::addStrings("11", "1") != "12") {
    throw std::runtime_error("error 1");
  }
  if (Solution::addStrings("1010", "1011") != "2021") {
    throw std::runtime_error("error 2");
  }
  return 0;
}
