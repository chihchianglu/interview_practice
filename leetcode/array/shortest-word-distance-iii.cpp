//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Shortest Word Distance III
 *
 * Given a list of words and two words word1 and word2, return the shortest distance between
 * these two words in the list.
 *
 * word1 and word2 may be the same and they represent two individual words in the list.
 *
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Input: word1 = “makes”, word2 = “coding”
 * Output: 1
 *
 * Input: word1 = "makes", word2 = "makes"
 * Output: 3
 */

#include <limits>
#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int shortestWordDistance(std::vector<std::string> &words, std::string word1, std::string word2) {
    int idx = -1, res = std::numeric_limits<int>::max(), n = words.size();
    for (int i = 0; i < n; ++i) {
      if (word1 == words[i] || word2 == words[i]) {
        if (idx != -1 && (word1 == word2 || words[i] != words[idx])) {
          res = std::min(res, i - idx);
        }
        idx = i;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec = {"practice", "makes", "perfect", "coding", "makes"};

  if (Solution::shortestWordDistance(vec, "makes", "coding") != 1) {
    throw std::runtime_error("error 3");
  }
  if (Solution::shortestWordDistance(vec, "makes", "makes") != 3) {
    throw std::runtime_error("error 4");
  }

  return 0;
}
