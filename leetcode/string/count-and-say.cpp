//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * Count and Say
 *
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth term of the count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a string.
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 *
 *
 * Example 2:
 *
 * Input: 4
 * Output: "1211"
 * Input Constraints:
 *
 * 1 <= n <= 30
 */

#include <string>
#include <stdexcept>

// 这道计数和读法问题还是第一次遇到，看似挺复杂，其实仔细一看，算法很简单，就是对于前一个数，找出相同元素的个数，把个数和该元素存到新的string里。
class Solution {
 public:
  static std::string countAndSay(int n) {
    if (n <= 0) {
      return std::string();
    }
    std::string res = "1";
    while (--n) {
      std::string cur;
      for (int i = 0; i < res.size(); ++i) {
        int count = 1;
        while (i + 1 < res.size() && res[i] == res[i + 1]) {
          ++count;
          ++i;
        }
        cur += std::to_string(count) + res[i];
      }
      res = cur;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::countAndSay(1) != "1") {
    throw std::runtime_error("error 1");
  }
  if (Solution::countAndSay(4) != "1211") {
    throw std::runtime_error("error 2");
  }
  return 0;
}
