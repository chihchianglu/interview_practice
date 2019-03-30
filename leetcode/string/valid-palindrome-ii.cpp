//
// Created by Lu, Chih-chiang on 2019-03-23.
//

/**
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 *
 * Example 1:
 * Input: "aba"
 * Output: True
 *
 * Example 2:
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 *
 * Note:
 * The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */

#include <string>
#include <stdexcept>

// 这道题是之前那道Valid Palindrome的拓展，还是让我们验证回复字符串，但是区别是这道题的字符串中只含有小写字母，
// 而且这道题允许删除一个字符，那么当遇到不匹配的时候，我们到底是删除左边的字符，还是右边的字符呢，我们的做法是两种情况都要算一遍，
// 只要有一种能返回true，那么结果就返回true。我们可以写一个子函数来判断字符串中的某一个范围内的子字符串是否为回文串
class Solution {
 public:
  static bool isValid(std::string s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
  static bool validPalindrome(std::string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return isValid(s, left, right - 1) || isValid(s, left + 1, right);
      }
      ++left;
      --right;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::validPalindrome("aba")) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::validPalindrome("abca")) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
