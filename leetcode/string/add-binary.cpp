//
// Created by Lu, Chih-chiang on 2019-02-22.
//

/**
 * Add Binary
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 * Input: s1 = "11", s2 = "1"
 * Output: "100"
 * Example 2:
 *
 * Input: s1 = "1010", s2 = "1011"
 * Output: "10101"
 */

#include <string>
#include <stdexcept>

class Solution {
 public:
  static std::string addBinary(std::string a, std::string b) {
    std::string res;
    int a_size = a.size() - 1, b_size = b.size() - 1, carry = 0;
    while (a_size >= 0 || b_size >= 0) {
      int p1 = a_size >= 0 ? a[a_size--] - '0' : 0;
      int p2 = b_size >= 0 ? b[b_size--] - '0' : 0;
      int sum = p1 + p2 + carry;
      res = std::to_string(sum % 2) + res;
      carry = sum / 2;
    }
    return carry ? "1" + res : res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::addBinary("11", "1") != "100") {
    throw std::runtime_error("error 1");
  }
  if (Solution::addBinary("1010", "1011") != "10101") {
    throw std::runtime_error("error 2");
  }
  return 0;
}
