//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3.
 *
 * Note that the answer must be a substring, "pwke" is a  * subsequence and not a substring.
 */

#include <string>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  // focus on this route
  static int lengthOfLongestSubstring(std::string s) {
    int res = 0, left = -1, n = s.size();
    std::unordered_map<char, int> m; // char -> index
    for (int i = 0; i < n; ++i) {
      if (m.count(s[i]) && m[s[i]] > left) {
        left = m[s[i]];
      }
      m[s[i]] = i;
      res = std::max(res, i - left);
    }
    return res;
  }
  static int lengthOfLongestSubstring_v2(std::string s) {
    int res = 0, left = 0, i = 0, n = s.size();
    std::unordered_set<char> t;
    while (i < n) {
      if (!t.count(s[i])) {
        t.insert(s[i++]);
        res = std::max(res, (int) t.size());
      } else {
        t.erase(s[left++]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::lengthOfLongestSubstring("abcabcbb") != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::lengthOfLongestSubstring("bbbbb") != 1) {
    throw std::runtime_error("error 2");
  }
  if (Solution::lengthOfLongestSubstring("pwwkew") != 3) {
    throw std::runtime_error("error 3");
  }
  if (Solution::lengthOfLongestSubstring("abcabcbb") != 3) {
    throw std::runtime_error("error 4");
  }
  if (Solution::lengthOfLongestSubstring("bbbbb") != 1) {
    throw std::runtime_error("error 5");
  }
  if (Solution::lengthOfLongestSubstring("pwwkew") != 3) {
    throw std::runtime_error("error 6");
  }
  return 0;
}
