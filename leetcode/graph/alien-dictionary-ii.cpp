//
// Created by Lu, Chih-chiang on 2019-01-18.
//

/**
 * Alien Dictionary II
 *
 * There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you.
 * You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules
 * of this new language. Derive the order of letters in this language.
 *
 * Example 1:
 * Given the following words in dictionary,
 *
 * [
 *   "wrt",
 *   "wrf",
 *   "er",
 *   "ett",
 *   "rftt"
 * ]
 * The correct order is: "wertf".
 *
 * Example 2:
 * Given the following words in dictionary,
 *
 * [
 *   "z",
 *   "x"
 * ]
 * The correct order is: "zx".
 *
 * Example 3:
 * Given the following words in dictionary,
 *
 * [
 *   "z",
 *   "x",
 *   "z"
 * ]
 * The order is invalid, so return "".
 *
 * Note:
 * You may assume all letters are in lowercase.
 * You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
 * If the order is invalid, return an empty string.
 * There may be multiple valid order of letters, return any one of them is fine.
 */

#include <set>
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  static std::string alienOrder(std::vector<std::string> &words) {
    std::string res;
    std::unordered_map<char, std::set<char>> graph;
    std::unordered_set<char> out_set;
    std::queue<char> queue;
    std::vector<int> in_degree(26, 0);

    // expected output in random order
    for (auto &word : words) {
      out_set.insert(word.begin(), word.end());
    }

    // build graph with in_degree
    for (int i = 0; i < words.size() - 1; ++i) {
      int min_size = std::min(words[i].size(), words[i + 1].size());
      for (int j = 0; j < min_size; ++j) {
        if (words[i][j] != words[i + 1][j]) {
          if (graph.find(words[i][j]) == graph.end()) {
            graph[words[i][j]] = std::set<char>();
          }
          if (!graph[words[i][j]].count(words[i + 1][j])) {
            ++in_degree[words[i + 1][j] - 'a'];
          }
          graph[words[i][j]].insert(words[i + 1][j]);
          break;
        }
      }
    }

    // collect all the start points, i.e.: in degree == 0
    for (int i = 0; i < in_degree.size(); ++i) {
      if (in_degree[i] == 0) {
        char c = char('a' + i);
        if (out_set.count(c)) {
          queue.push(c);
        }
      }
    }

    // form the possible answer
    while (!queue.empty()) {
      char c = queue.front();
      queue.pop();
      res += c;
      if (graph.count(c)) {
        for (auto ch : graph[c]) {
          --in_degree[ch - 'a'];
          if (in_degree[ch - 'a'] == 0) {
            queue.push(ch);
          }
        }
      }
    }
    return res.size() != out_set.size() ? std::string() : res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> words = {"wrt", "wrf", "er", "ett", "rftt"};
  if (Solution::alienOrder(words) != "wertf") {
    throw std::runtime_error("error");
  }
  return 0;
}
