//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * Implement strStr()
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Example 1:
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 * Example 2:
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr()
 * and Java's indexOf().
 */

#include <string>
#include <stdexcept>

// 这道题让我们在一个字符串中找另一个字符串第一次出现的位置，那我们首先要做一些判断，如果子字符串为空，则返回0，
// 如果子字符串长度大于母字符串长度，则返回-1。然后我们开始遍历母字符串，我们并不需要遍历整个母字符串，
// 而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率。然后对于每一个字符，我们都遍历一遍子字符串，
// 一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可
class Solution {
 public:
  static int strStr(std::string haystack, std::string needle) {
    int m = haystack.size(), n = needle.size(), upper_bound = m - n;
    if (n == 0) {
      return 0;
    } else if (upper_bound < 0) {
      return -1;
    }
    for (int i = 0; i <= upper_bound; ++i) {
      int j = 0;
      for (j = 0; j < n; ++j) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == n) {
        return i;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::strStr("hello", "ll") != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::strStr("aaaaa", "bba") != -1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
