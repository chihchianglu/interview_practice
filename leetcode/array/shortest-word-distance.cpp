//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Shortest Word Distance
 *
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the
 * list.
 *
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 *
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

#include <limits>
#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int shortestDistance_v1(std::vector<std::string> &words, std::string word1, std::string word2) {
    int p1 = -1, p2 = -1, res = std::numeric_limits<int>::max(), n = words.size();
    for (int i = 0; i < n; ++i) {
      if (word1 == words[i]) {
        p1 = i;
      } else if (word2 == words[i]) {
        p2 = i;
      }
      if (p1 != -1 && p2 != -1) {
        res = std::min(res, std::abs(p1 - p2));
      }
    }
    return res;
  }
  static int shortestDistance(std::vector<std::string> &words, std::string word1, std::string word2) {
    int idx = -1, res = std::numeric_limits<int>::max(), n = words.size();
    for (int i = 0; i < n; ++i) {
      if (word1 == words[i] || word2 == words[i]) {
        if (idx != -1 && words[idx] != words[i]) {
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

  if (Solution::shortestDistance_v1(vec, "coding", "practice") != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::shortestDistance_v1(vec, "makes", "coding") != 1) {
    throw std::runtime_error("error 2");
  }
  if (Solution::shortestDistance(vec, "coding", "practice") != 3) {
    throw std::runtime_error("error 3");
  }
  if (Solution::shortestDistance(vec, "makes", "coding") != 1) {
    throw std::runtime_error("error 4");
  }

  return 0;
}
