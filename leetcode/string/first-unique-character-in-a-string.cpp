//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * First Unique Character in a String
 *
 * Given a string, find the first non-repeating character in it and return it's index.
 * If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 */

#include <string>
#include <stdexcept>
#include <unordered_map>

// 这道题确实没有什么难度，我们只要用哈希表建立每个字符和其出现次数的映射，然后按顺序遍历字符串，找到第一个出现次数为1的字符，返回其位置即可
class Solution {
 public:
  static int firstUniqChar(std::string s) {
    std::unordered_map<char, int> m;
    for (char c : s) {
      ++m[c];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (m[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::firstUniqChar("leetcode") != 0) {
    throw std::runtime_error("error 1");
  }
  if (Solution::firstUniqChar("loveleetcode") != 2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
