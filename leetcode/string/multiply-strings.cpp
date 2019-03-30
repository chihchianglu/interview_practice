//
// Created by Lu, Chih-chiang on 2019-02-22.
//

/**
 * Multiply Strings
 *
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also
 * represented as a string.
 *
 * Example 1:
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * Note:
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::string multiply(std::string num1, std::string num2) {
    std::string res;
    int n1 = num1.size(), n2 = num2.size();
    std::vector<int> v(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; --i) {
      for (int j = n2 - 1; j >= 0; --j) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int pos1 = i + j; // carry pos
        int pos2 = i + j + 1; // value pos
        int sum = mul + v[pos2]; // prev carry

        v[pos1] += sum / 10; // carry
        v[pos2] = sum % 10; // value
      }
    }

    // skip leading 0
    int end = n1 + n2 - 1, begin = 0;
    while (begin <= end && v[begin] == 0) {
      ++begin;
    }
    for (; begin <= end; ++begin) {
      res.push_back(v[begin] + '0');
    }
    return res.empty() ? "0" : res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::multiply("2", "3") != "6") {
    throw std::runtime_error("error 1");
  }
  if (Solution::multiply("123", "456") != "56088") {
    throw std::runtime_error("error 2");
  }
  if (Solution::multiply("0", "0") != "0") {
    throw std::runtime_error("error 3");
  }
  return 0;
}
