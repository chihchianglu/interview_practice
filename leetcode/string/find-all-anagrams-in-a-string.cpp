//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * Find All Anagrams in a String
 *
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,
 * 100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

#include <string>
#include <vector>
#include <stdexcept>

// 这道题给了我们两个字符串s和p，让我们在s中找字符串p的所有变位次的位置，所谓变位次就是字符种类个数均相同但是顺序可以不同的两个词，
// 那么我们肯定首先就要统计字符串p中字符出现的次数，然后从s的开头开始，每次找p字符串长度个字符，来验证字符个数是否相同，
// 如果不相同出现了直接break，如果一直都相同了，则将起始位置加入结果res中
class Solution {
 public:
  static std::vector<int> findAnagrams(std::string s, std::string p) {
    if (s.empty()) {
      return {};
    }
    std::vector<int> res, cnt(26, 0);
    int ns = s.size(), np = p.size(), i = 0;
    for (char c : p) {
      ++cnt[c - 'a'];
    }
    int upper_bound = ns - np;
    while (i <= upper_bound) {
      bool success = true;
      std::vector<int> tmp = cnt;
      for (int j = i; j < i + np; ++j) {
        if (--tmp[s[j] - 'a'] < 0) {
          success = false;
          break;
        }
      }
      if (success) {
        res.push_back(i);
      }
      ++i;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> out_1 = {0, 6};
  std::vector<int> out_2 = {0, 1, 2};
  if (Solution::findAnagrams("cbaebabacd", "abc") != out_1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findAnagrams("abab", "ab") != out_2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
