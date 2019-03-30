//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * Add Bold Tag in String
 *
 * Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b>
 * to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them
 * together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive,
 * you need to combine them.
 *
 * Example 1:
 * Input:
 * s = "abcxyz123"
 * dict = ["abc","123"]
 * Output:
 * "<b>abc</b>xyz<b>123</b>"
 *
 * Example 2:
 * Input:
 * s = "aaabbcc"
 * dict = ["aaa","aab","bc"]
 * Output:
 * "<b>aaabbc</b>c"
 *
 * Note:
 * The given dict won't contain duplicates, and its length won't exceed 100.
 * All the strings in input have length in range [1, 1000].
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>

// use unordered_set to store the index of "s" that matches the dict
// then, loop through "s", and print the bold tag
class Solution {
 public:
  static std::string addBoldTag(std::string s, std::vector<std::string> &dict) {
    std::string res;
    int n = s.size();
    std::unordered_set<int> bold;
    for (auto word : dict) {
      int len = word.size();
      for (int i = 0; i <= n - len; ++i) {
        if (s[i] == word[0] && s.substr(i, len) == word) {
          for (int j = i; j < i + len; ++j) {
            bold.insert(j);
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (bold.count(i) && !bold.count(i - 1)) {
        res += "<b>";
      }
      res += s[i];
      if (bold.count(i) && !bold.count(i + 1)) {
        res += "</b>";
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec1 = {"abc", "123"};
  std::vector<std::string> vec2 = {"aaa", "aab", "bc"};
  if (Solution::addBoldTag("abcxyz123", vec1) != "<b>abc</b>xyz<b>123</b>") {
    throw std::runtime_error("error 1");
  }
  if (Solution::addBoldTag("aaabbcc", vec2) != "<b>aaabbc</b>c") {
    throw std::runtime_error("error 2");
  }
  return 0;
}
