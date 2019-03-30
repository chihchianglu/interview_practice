//
// Created by Lu, Chih-chiang on 2019-02-02.
//

/**
 * Additive Number
 *
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers,
 * each subsequent number in the sequence must be the sum of the preceding two.
 *
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Example 1:
 *
 * Input: "112358"
 * Output: true
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 *              1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 * Example 2:
 *
 * Input: "199100199"
 * Output: true
 * Explanation: The additive sequence is: 1, 99, 100, 199.
 *              1 + 99 = 100, 99 + 100 = 199
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 */

#include <string>
#include <stdexcept>

class Solution {
 public:
  static std::string add(std::string s1, std::string s2) {
    int n1 = s1.size(), n2 = s2.size(), i = n1 - 1, j = n2 - 1, carry = 0;
    std::string res;
    while (i >= 0 || j >= 0) {
      int sum = carry + (i >= 0 ? s1[i--] - '0' : 0) + (j >= 0 ? s2[j--] - '0' : 0);
      res.insert(res.begin(), sum % 10 + '0');
      carry = sum / 10;
    }
    if (carry) res.insert(res.begin(), '1');
    return res;
  }

  static bool dfs(std::string s1, std::string s2, std::string res) {
    if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) {
      return false;
    }
    // std::string sum = std::to_string(std::stoi(s1) + std::stoi(s2));
    std::string sum = add(s1, s2);
    if (res == sum) {
      return true;
    } else if (res.size() < sum.size() || res.substr(0, sum.size()) != sum) {
      return false;
    } else {
      return dfs(s2, sum, res.substr(sum.size()));
    }
  }

  static bool isAdditiveNumber(std::string num) {
    int n = num.size();
    // the 1st 2 numbers length can't longer than half of the string
    for (int i = 1; i <= n / 2; ++i) {
      for (int j = 1; j <= (n - i) / 2; ++j) {
        if (n - i - j < std::min(i, j)) {
          continue;
        }
        if (dfs(num.substr(0, i), num.substr(i, j), num.substr(i + j))) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::isAdditiveNumber("112")) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::isAdditiveNumber("199100199")) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
