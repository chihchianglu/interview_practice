//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * Longest Substring with At Most Two Distinct Characters
 *
 * Given a string s , find the length of the longest substring t that contains at most k distinct characters.
 *
 * Example 1:
 *
 * Input: "eceba", k = 2
 * Output: 3
 * Explanation: t is "ece" which its length is 3.
 * Example 2:
 *
 * Input: "ccaabbb", k = 2
 * Output: 5
 * Explanation: t is "aabbb" which its length is 5.
 */

#include <string>
#include <unordered_map>

class Solution {
 public:
  static int lengthOfLongestSubstringTwoDistinct(std::string s, int k) {
    int res = 0, left = 0, n = s.size();
    std::unordered_map<char, int> m;
    for (int i = 0; i < n; ++i) {
      ++m[s[i]];
      while (m.size() > k) {
        if (--m[s[left]] == 0) {
          m.erase(s[left]);
        }
        ++left;
      }
      res = std::max(res, i - left + 1);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::lengthOfLongestSubstringTwoDistinct("eceba", 2) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::lengthOfLongestSubstringTwoDistinct("ccaabbb", 2) != 5) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
