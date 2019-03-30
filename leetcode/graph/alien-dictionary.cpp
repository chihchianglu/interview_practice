//
// Created by Lu, Chih-chiang on 2019-01-18.
//

/**
 * Alien Dictionary
 *
 * There is a new alien language which uses the latin alphabet. The order among letters are known to you and sorted.
 * You receive a list of non-empty words from the dictionary, write a program to verify whether the words
 * are sorted lexicographically by the rules of this new language.
 *
 * Example 1:
 * The order of the letters is "cba", the list of words is ["cc", "ab", "ca"]
 * Your program should return false, because "ca" should be in front of "ab".
 *
 * Note:
 * You may assume all letters are in lowercase.
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static bool alienOrder(std::vector<std::string> &words, std::string in_string) {
    std::unordered_map<char, int> ch_to_idx_map;
    if (in_string.empty()) {
      return false;
    }

    // make char to index map for in_string -> the correct order
    for (int i = 0; i < in_string.size(); ++i) {
      ch_to_idx_map[in_string[i]] = i;
    }

    // compare words dictionary pair to make sure the index is accurate
    for (int i = 0; i < words.size() - 1; ++i) {
      int min_size = std::min(words[i].size(), words[i + 1].size());
      int w1_length = words[i].size();
      int w2_length = words[i + 1].size();

      if (w1_length > w2_length) {
        return false;
      }
      for (int j = 0; j < min_size; ++j) {
        if (words[i][j] != words[i + 1][j]) {
          if (ch_to_idx_map[words[i][j]] > ch_to_idx_map[words[i + 1][j]]) {
            return false;
          } else {
            break;
          }
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> words1 = {"cc", "ab", "ca"};
  if (Solution::alienOrder(words1, "cba")) {
    throw std::runtime_error("error");
  }
  return 0;
}
