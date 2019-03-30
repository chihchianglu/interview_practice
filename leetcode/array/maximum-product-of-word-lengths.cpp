//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Product of Word Lengths
 *
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not
 * share common letters. You may assume that each word will contain only lower case letters. If no such two words exist,
 *  return 0.
 *
 * Example 1:
 *
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 * Example 2:
 *
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 * Example 3:
 *
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 */

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
 public:
  static int maxProduct(std::vector<std::string> &words) {
    int res = 0, n = words.size();
    std::vector<int> mask(n, 0);
    for (int i = 0; i < n; ++i) {
      for (char c : words[i]) {
        mask[i] |= (1 << (c - 'a'));
      }
      for (int j = 0; j < i; ++j) {
        if (!(mask[j] & mask[i])) {
          res = std::max(res, int(words[i].size() * words[j].size()));
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  std::vector<std::string> vec2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  std::vector<std::string> vec3 = {"a", "aa", "aaa", "aaaa"};
  if (Solution::maxProduct(vec1) != 16) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxProduct(vec2) != 4) {
    throw std::runtime_error("error 2");
  }
  if (Solution::maxProduct(vec3) != 0) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
